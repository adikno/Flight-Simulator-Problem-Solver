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
        virtual int main(int argc , char* args) = 0;
    };
};


#endif //UNTITLED14_BOOT_H
