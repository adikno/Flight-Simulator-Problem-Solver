//
// Created by adi on 11/01/19.
//

#ifndef UNTITLED14_MYPARAMS_H
#define UNTITLED14_MYPARAMS_H

#include "ClientHandler.h"
#include "TasksQueue.h"

struct myParams {
        int port;
        ClientHandler *c;
        bool run = true;
        TasksQueue *tasks;
        queue<std::thread> *workers;
    };

#endif //UNTITLED14_MYPARAMS_H
