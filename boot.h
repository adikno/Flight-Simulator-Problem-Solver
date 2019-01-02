//
// Created by michal on 12/30/18.
//

#ifndef UNTITLED14_BOOT_H
#define UNTITLED14_BOOT_H


#include "Server.h"
#include "MySerialServer.h"
#include "FileCacheManger.h"
#include "Solver.h"
#include "MyTestClientHandler.cpp";


namespace boot {

    class Main{
    public:
        int main(int argc , char* args){
            Solver *solver = new Solver();
            CacheManager *cacheManager = new FileCacheManager();
            ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager) ;
            Server *server = new MySerialServer(30);
            server->open(args[0], clientHandler);
        }
    };
};


#endif //UNTITLED14_BOOT_H
