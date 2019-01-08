//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_SERVER_H
#define UNTITLED14_SERVER_H

#include <bits/sigaction.h>
#include "ClientHandler.h"

namespace server_side {
    class Server {

    public:
        virtual void open(int port, ClientHandler *c) = 0;

        virtual void stop() = 0;
    };
}
#endif //UNTITLED14_SERVER_H
