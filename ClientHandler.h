//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_CLIENTHANDLER_H
#define UNTITLED14_CLIENTHANDLER_H


#include <iostream>
#include "CacheManager.h"
#include "Solver.h"

using  namespace std;

class ClientHandler{
protected:
    CacheManager *cm;

public:
    ClientHandler(CacheManager *cacheManager){
        cm = cacheManager;
    }
    virtual void handleClient (int clientSock) = 0;

    virtual ~ClientHandler() = default;

    virtual CacheManager* getCacheManager() = 0;

    virtual Solver* getSolver() = 0;
};

#endif //UNTITLED14_CLIENTHANDLER_H