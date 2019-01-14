//
// Created by adi on 11/01/19.
//

#ifndef UNTITLED14_PARALLELSERVER_H
#define UNTITLED14_PARALLELSERVER_H


#include "Server.h"
#include "TasksQueue.h"
#include "MatrixTask.h"

extern pthread_mutex_t mutexMap;
extern pthread_mutex_t mutexFile;
extern bool run;

namespace server_side {

    class ParallelServer : public Server {
        struct myParams *params;
        queue<std::thread> workers;
        TasksQueue tasks_queue;
    public:

        ParallelServer();

        void open(int port, ClientHandler *c) override;

        void stop() override;

        ~ParallelServer(){
            pthread_mutex_destroy(&mutexMap);
            pthread_mutex_destroy(&mutexFile);
        }
    };

}


#endif //UNTITLED14_PARALLELSERVER_H
