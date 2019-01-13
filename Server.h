//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_SERVER_H
#define UNTITLED14_SERVER_H

#include <signal.h>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include "OpenSocket.cpp"
#include "ClientHandler.h"
#include "MyParams.h"


namespace server_side {
    class Server {

    public:
        virtual void open(int port, ClientHandler *c) = 0;

        virtual void stop() = 0;

    };

}
#endif //UNTITLED14_SERVER_H
