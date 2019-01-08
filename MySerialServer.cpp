//
// Created by michal on 12/28/18.
//

#include "MySerialServer.h"
#include <vector>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include "OpenSocket.cpp"

using namespace std;

struct membuf :std::streambuf{
    membuf(char* begin, char* end){
        this->setg(begin,begin,end);
    }
};
void MySerialServer::open(int port, ClientHandler *c) {
   // auto *open = new OpenSocket();
    thread t1(this, port, c);
}

void MySerialServer::stop() {
    run = false;
}

void MySerialServer::openSocket(int port, ClientHandler *c) {
    int sockfd, newsockfd, clilen;
    char input[1024];
    char output[1024];
    string tempInput;
    struct sockaddr_in serv_addr, cli_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int n;
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Now bind the host address using bind() call.
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Now start listening for the clients, here process will
    //  go in sleep mode and will wait for the incoming connection


    listen(sockfd, 1);
    clilen = sizeof(cli_addr);
    while (run) {

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        while (tempInput != "end") {
            bzero(input, 1024);
            n = read(newsockfd, input, 1023);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            membuf sbuf1(input, input + sizeof(input));
            membuf sbuf2(output, output + sizeof(output));
            istream in(&sbuf1);
            ostream os(&sbuf2);
            c->handleClient(os, in);
            ostringstream stream1;
            stream1 << os.rdbuf();
            std::string str =  stream1.str();
            if(::send(sockfd, str.data(),str.size(),0) < 0){
                perror("ERROR writing to socket");
                exit(1);
            }
            tempInput = input;
        }
    }
    close(sockfd);
}
