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
    char finalProb[1024] = "";
    bzero(temp, 1024);
    n = read(clientSock, temp, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    strcat(problem, temp);
    //strcat(problem, "\n");
    while (strstr(problem, "end") == nullptr) {
        bzero(temp, 1024);
        n = read(clientSock, temp, 1023);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        strcat(problem, temp);
        //strcat(problem, "\n");
    }
    int i = 0;
    bzero(finalProb, 1024);
    while (problem[i] != 'e') {
        finalProb[i] = problem[i];
        i++;
    }
    if (cm->isExist(finalProb)) {
        solution = cm->getSulotion(finalProb);
    } else {
        solution = solver->getSolution(finalProb);
        cm->saveSolution(finalProb, solution);
    }
    char output[solution.size()] = "";
    strcpy(output, solution.data());
    if(write(clientSock, output, solution.size()) < 0){
        perror("ERROR writing to socket");
        exit(1);
    }

    close(clientSock);
    //output.flush();

}
