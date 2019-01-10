//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_MYSERIALSERVER_H
#define UNTITLED14_MYSERIALSERVER_H

#include <signal.h>
#include "Server.h"
namespace server_side {

    class MySerialServer : public Server {
        bool run = true;
        int timeout;
    public:

        MySerialServer(int timeout) {
            timeout = timeout;
        }

        void open(int port, ClientHandler *c) override;

        void stop() override;

        void openSocket(int port, ClientHandler *c);
    };


}
#endif //UNTITLED14_MYSERIALSERVER_H
