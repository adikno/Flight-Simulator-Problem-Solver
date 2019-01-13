//
// Created by michal on 12/30/18.
//
#include <signal.h>
//#include "main.h"
#include "Server.h"
#include "SerialServer.h"
#include "FileCacheManger.h"
#include "GeneralClientHandler.cpp"
#include "SearcherSolver.h"
#include "BestFirstSearch.h"
#include "MatrixHandler.h"

int main(int argc , char* argv[]){
    Searcher<Point> *searcher = new BestFirstSearch<Point>();
    auto *solver = new SearcherSolver(searcher);
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MatrixHandler(solver, cacheManager);
    server_side::Server *server = new server_side::SerialServer();
    server->open(atoi(argv[1]), clientHandler);
    while(true);


/*
    string path = solver->getSolution("4\n1,0,2,11\n3,2,1,2\n0,2,0,1\n,5,2,1,1\n");
    cout << path << endl;
    cout << searcher->getPathCost() << endl;
    cout << searcher->getNumberOfNodesEvaluated() << endl;
*/
}