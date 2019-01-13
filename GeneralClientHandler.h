//
// Created by adi on 11/01/19.
//

#ifndef UNTITLED14_GENERALCLIENTHANDLER_H
#define UNTITLED14_GENERALCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"


class GeneralClientHandler: public ClientHandler{
    Solver *solver;
public:
    GeneralClientHandler(Solver *solver1, CacheManager *cm): ClientHandler(cm) {
        this->solver = solver1;
    }
    void handleClient(int clientSock) override {
        string solution;
        long n;
        char problem[256] = "";
        //char output[256] = "";

        bzero(problem, 1024);
        n = read(clientSock, problem, 1023);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        while (strcmp(problem, "end") != 0) {
            if (cm->isExist(problem)) {
                solution = cm->getSulotion(problem);
            } else {
                solution = solver->getSolution(problem);
                cm->saveSolution(problem, solution);
            }

            //strcpy(output, solution.data());
            if(::send(clientSock, solution.data(), solution.size(),0) < 0){
                perror("ERROR writing to socket");
                exit(1);
            }
            //output.flush();

            bzero(problem, 1024);
            n = read(clientSock, problem, 1023);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
        }
    }

};

#endif //UNTITLED14_GENERALCLIENTHANDLER_H
