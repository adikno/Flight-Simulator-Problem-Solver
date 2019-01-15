//
// Created by michal on 12/28/18.
//

#include "SerialServer.h"
#include "ParallelServer.h"
#include <pthread.h>

using namespace std;
using namespace server_side;

void* openSocket(void* arg) {
    struct myParams *params = (myParams*) arg;
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(params->port);

    // Now bind the host address using bind() call.
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Now start listening for the clients, here process will
    //  go in sleep mode and will wait for the incoming connection

    listen(sockfd, 1);
    clilen = sizeof(cli_addr);

    bool first = true;

    while (run) {

        if (!first) {
            timeval timeout;
            timeout.tv_sec = 10;
            timeout.tv_usec = 0;

            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
            if (newsockfd < 0) {
                if (errno == EWOULDBLOCK) {
                    cout << "timeout!" << endl;
                    run = false;
                    continue;
                } else {
                    perror("other error");
                    run = false;
                    continue;
                }
            }
        } else {
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
            if (newsockfd < 0) {
                perror("error");
                run = false;
                continue;
            }
            first = false;
        }

        params->c->handleClient(newsockfd);

        close(newsockfd);
    }
    close(sockfd);
    return nullptr;
}

void SerialServer::open(int port, ClientHandler *c) {
    this->params->port = port;
    this->params->c = c;
    pthread_t trid;
    pthread_create(&trid, nullptr, openSocket, this->params);
    //pthread_join(&trid, nullptr);
}

void SerialServer::stop() {
    run = false;
}
