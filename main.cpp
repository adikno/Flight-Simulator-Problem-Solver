//
// Created by michal on 12/30/18.
//
#include <signal.h>
//#include "main.h"
#include "StringReverser.h"
#include "Server.h"
#include "MySerialServer.h"
#include "FileCacheManger.h"
#include "MyTestClientHandler.cpp"
#include "Matrix.h"
#include "SearcherSolver.h"
#include "DFS.h"
#include "BFS.h"
#include "BestFirstSearch.h"


int main(int argc , char** args){
    Searcher<Point> *searcher = new BestFirstSearch<Point>();
    auto *solver = new SearcherSolver(searcher);
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
    server_side::Server *server = new server_side::MySerialServer(30);
    server->open(12345, clientHandler);

/*
    string path = solver->getSolution("4\n1,0,2,11\n3,2,1,2\n0,2,0,1\n,5,2,1,1\n");
    cout << path << endl;
    cout << searcher->getPathCost() << endl;
    cout << searcher->getNumberOfNodesEvaluated() << endl;
*/
}