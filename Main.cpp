//
// Created by michal on 12/30/18.
//

#include "Main.h"
#include "StringReverser.h"

int boot::Main::main(int argc , char* args){
    Solver<string, string> *solver = new StringReverser();
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
    server_side::Server *server = new MySerialServer(30);
    server->open(args[0], clientHandler);
}