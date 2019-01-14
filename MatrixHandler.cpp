//
// Created by adi on 11/01/19.
//

#include <memory.h>
#include <unistd.h>
#include <sys/socket.h>
#include "MatrixHandler.h"

MatrixHandler::MatrixHandler(Solver *solver1, CacheManager *cacheManager) : ClientHandler(cacheManager) {
    this->solver = solver1;
}

void MatrixHandler::handleClient(int clientSock) {
    string solution;
    long n;
    char problem[1024] = "";
    char temp[1024] = "";
    char output[1024] = "";

    bzero(temp, 1024);
    n = read(clientSock, temp, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    while (strcmp(temp, "end") != 0) {
        strcat(problem, temp);
        strcat(problem, "\n");
        bzero(temp, 1024);
        n = read(clientSock, temp, 1023);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
    }
    if (cm->isExist(problem)) {
        solution = cm->getSulotion(problem);
    } else {
        solution = solver->getSolution(problem);
        cm->saveSolution(problem, solution);
    }

    strcpy(output, solution.data());
    if(write(clientSock, output, 1023) < 0){
        perror("ERROR writing to socket");
        exit(1);
    }

    close(clientSock);
    //output.flush();

}
