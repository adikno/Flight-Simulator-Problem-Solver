//
// Created by michal on 12/30/18.
//
#include <signal.h>
#include "Main.h"
#include "Server.h"
#include "FileCacheManger.h"
#include "SearcherSolver.h"
#include "AStar.h"
#include "MatrixHandler.h"
#include "ParallelServer.h"

pthread_mutex_t mutexMap;
pthread_mutex_t mutexFile;
bool run;

int boot::Main::main(int argc, char *args[]) {
    pthread_mutex_init(&mutexMap, nullptr);
    pthread_mutex_init(&mutexFile, nullptr);
    run = true;
    Searcher<Point> *searcher = new AStar<Point>();

    auto *solver = new SearcherSolver(searcher);
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MatrixHandler(solver, cacheManager);
    server_side::Server *server = new server_side::ParallelServer();
    server->open(atoi(args[1]), clientHandler);
}