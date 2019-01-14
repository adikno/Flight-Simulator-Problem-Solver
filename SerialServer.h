//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_SERIALSERVER_H
#define UNTITLED14_SERIALSERVER_H

#include <signal.h>
#include "Server.h"
#include <thread>

namespace server_side {

    class SerialServer : public Server {
        struct myParams *params;
    public:

        SerialServer() {
            this->params = new myParams();
        }

        void open(int port, ClientHandler *c) override;

        void stop() override;
    };


}
#endif //UNTITLED14_SERIALSERVER_H
