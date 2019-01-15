//
// Created by adi on 11/01/19.
//

#ifndef UNTITLED14_MATRIXHANDLER_H
#define UNTITLED14_MATRIXHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"

class MatrixHandler: public ClientHandler {
    Solver *solver;
public:
    MatrixHandler(Solver *solver1, CacheManager *cacheManager);

    void handleClient(int clientSock) override;

    ~MatrixHandler() override {
        //delete this->cm;
        //delete this->solver;
    }

    CacheManager* getCacheManager() override {
        return this->cm;
    }

    Solver* getSolver() override {
        return this->solver;
    }


};


#endif //UNTITLED14_MATRIXHANDLER_H
