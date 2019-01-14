//
// Created by adi on 14/01/19.
//

#ifndef UNTITLED14_MATRIXTASK_H
#define UNTITLED14_MATRIXTASK_H


#include "Task.h"
#include "ClientHandler.h"

class MatrixTask: public Task {
    ClientHandler *c;
    int clientSock;
public:
    MatrixTask(ClientHandler *c, int socket) {
        this->c = c;
        this->clientSock = socket;
    }
    void execute() override {
        this->c->handleClient(this->clientSock);
    }

    ~MatrixTask() override {
        delete c;
    }
};


#endif //UNTITLED14_MATRIXTASK_H
