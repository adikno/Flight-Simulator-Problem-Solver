//
// Created by adi on 11/01/19.
//

#ifndef UNTITLED14_MYPARAMS_H
#define UNTITLED14_MYPARAMS_H

#include "ClientHandler.h"

    struct myParams {
        int port;
        ClientHandler *c;
        bool run = true;
    };

#endif //UNTITLED14_MYPARAMS_H
