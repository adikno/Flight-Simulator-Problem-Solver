//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_CLIENTHANDLER_H
#define UNTITLED14_CLIENTHANDLER_H


#include <iostream>
#include "CacheManager.h"

using  namespace std;

class ClientHandler{
protected:
    CacheManager *cm;

public:
    ClientHandler(CacheManager *cacheManager){
        cm = cacheManager;
    }
    virtual void handleClient (ostream &output, istream &input) =0;
};

#endif //UNTITLED14_CLIENTHANDLER_H