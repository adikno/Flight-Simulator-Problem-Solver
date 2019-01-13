//
// Created by adi on 11/01/19.
//

#ifndef UNTITLED14_PARALLELSERVER_H
#define UNTITLED14_PARALLELSERVER_H


#include "Server.h"

namespace server_side {

    class ParallelServer : public Server {
        vector<struct myParams*> params;
    public:

        ParallelServer() = default;

        void open(int port, ClientHandler *c) override;

        void stop() override;
    };


}


#endif //UNTITLED14_PARALLELSERVER_H
