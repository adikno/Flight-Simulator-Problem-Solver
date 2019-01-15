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
#include "MatrixGenerator.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"
#include "MatrixHandler.h"
#include "BestFirstSearch.h"
#include "ParallelServer.h"
#include "GraphFile.h"
#include "SolutionFile.h"

pthread_mutex_t mutexMap;
pthread_mutex_t mutexFile;
bool run = true;
int main(int argc, char *argv[]) {

    srand (time(NULL));
    auto *graphFile = new GraphFile();
    SolutionFile *solutionFile = new SolutionFile();
    for (int i = 0; i< 10; i++){
        Searcher<Point> *searcher = new BestFirstSearch<Point>();
        Searcher<Point> *searcher1 = new DFS<Point>();
        Searcher<Point> *searcher2 = new BFS<Point>();
        Searcher<Point> *searcher3 = new AStar<Point>();
        MatrixGenerator *matrixGenarator = new MatrixGenerator;
        matrixGenarator->create();
        Matrix *matrix  = matrixGenarator->getMatrix();
        Searchable<Point> *searchable = matrix;
        graphFile->write(matrix);
        searcher->search(searchable);
        solutionFile->write(searcher->getPathCost(),searcher->getNumberOfNodesEvaluated());
        matrix->initDis();
        searcher1->search(searchable);
        solutionFile->write(searcher1->getPathCost(),searcher1->getNumberOfNodesEvaluated());
        matrix->initDis();
        searcher2->search(searchable);
        solutionFile->write(searcher2->getPathCost(),searcher2->getNumberOfNodesEvaluated());
        matrix->initDis();
        searcher3->search(searchable);
        solutionFile->write(searcher3->getPathCost(),searcher3->getNumberOfNodesEvaluated());
        }
/*
        pthread_mutex_init(&mutexMap, nullptr);
    pthread_mutex_init(&mutexFile, nullptr);
    auto *solver = new SearcherSolver(searcher);
    /*
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MatrixHandler(solver, cacheManager);
    server_side::Server *server = new server_side::ParallelServer();
    server->open(atoi(argv[1]), clientHandler);
     */
    CacheManager *cacheManager = new FileCacheManager();
/*
    auto *solver = new SearcherSolver(searcher);
    auto *solver1 = new SearcherSolver(searcher1);

    auto *solver2 = new SearcherSolver(searcher2);
    auto *solver3 = new SearcherSolver(searcher3);
    bool x = cacheManager->isExist("9.000000,3.000000,15.000000,20.000000,4.000000,12.000000,11.000000,5.000000\n"
                                   "4.000000,5.000000,8.000000,11.000000,4.000000,9.000000,17.000000,21.000000\n"
                                   "7.000000,18.000000,7.000000,21.000000,5.000000,13.000000,17.000000,8.000000\n"
                                   "18.000000,18.000000,15.000000,21.000000,18.000000,7.000000,8.000000,18.000000\n"
                                   "8.000000,14.000000,16.000000,10.000000,16.000000,17.000000,5.000000,19.000000\n"
                                   "12.000000,12.000000,8.000000,14.000000,19.000000,16.000000,5.000000,16.000000\n"
                                   "4.000000,11.000000,15.000000,8.000000,14.000000,11.000000,6.000000,10.000000\n"
                                   "19.000000,19.000000,2.000000,16.000000,4.000000,20.000000,12.000000,3.000000\n");
    string path = solver->getSolution("9.000000,3.000000,15.000000,20.000000,4.000000,12.000000,11.000000,5.000000\n"
"4.000000,5.000000,8.000000,11.000000,4.000000,9.000000,17.000000,21.000000\n"
"7.000000,18.000000,7.000000,21.000000,5.000000,13.000000,17.000000,8.000000\n"
"18.000000,18.000000,15.000000,21.000000,18.000000,7.000000,8.000000,18.000000\n"
"8.000000,14.000000,16.000000,10.000000,16.000000,17.000000,5.000000,19.000000\n"
"12.000000,12.000000,8.000000,14.000000,19.000000,16.000000,5.000000,16.000000\n"
"4.000000,11.000000,15.000000,8.000000,14.000000,11.000000,6.000000,10.000000\n"
"19.000000,19.000000,2.000000,16.000000,4.000000,20.000000,12.000000,3.000000\n"
                                       "0,0\n"
                                       "7,7\n");
    cacheManager->saveSolution("9.000000,3.000000,15.000000,20.000000,4.000000,12.000000,11.000000,5.000000\n"
                               "4.000000,5.000000,8.000000,11.000000,4.000000,9.000000,17.000000,21.000000\n"
                               "7.000000,18.000000,7.000000,21.000000,5.000000,13.000000,17.000000,8.000000\n"
                               "18.000000,18.000000,15.000000,21.000000,18.000000,7.000000,8.000000,18.000000\n"
                               "8.000000,14.000000,16.000000,10.000000,16.000000,17.000000,5.000000,19.000000\n"
                               "12.000000,12.000000,8.000000,14.000000,19.000000,16.000000,5.000000,16.000000\n"
                               "4.000000,11.000000,15.000000,8.000000,14.000000,11.000000,6.000000,10.000000\n"
                               "19.000000,19.000000,2.000000,16.000000,4.000000,20.000000,12.000000,3.000000\n",path);
    delete cacheManager;
    string path1 = solver1->getSolution("9.000000,3.000000,15.000000,20.000000,4.000000,12.000000,11.000000,5.000000\n"
                                        "4.000000,5.000000,8.000000,11.000000,4.000000,9.000000,17.000000,21.000000\n"
                                        "7.000000,18.000000,7.000000,21.000000,5.000000,13.000000,17.000000,8.000000\n"
                                        "18.000000,18.000000,15.000000,21.000000,18.000000,7.000000,8.000000,18.000000\n"
                                        "8.000000,14.000000,16.000000,10.000000,16.000000,17.000000,5.000000,19.000000\n"
                                        "12.000000,12.000000,8.000000,14.000000,19.000000,16.000000,5.000000,16.000000\n"
                                        "4.000000,11.000000,15.000000,8.000000,14.000000,11.000000,6.000000,10.000000\n"
                                        "19.000000,19.000000,2.000000,16.000000,4.000000,20.000000,12.000000,3.000000\n"
                                        "0,0\n"
                                        "7,7\n");
    string path2 = solver2->getSolution("9.000000,3.000000,15.000000,20.000000,4.000000,12.000000,11.000000,5.000000\n"
                                        "4.000000,5.000000,8.000000,11.000000,4.000000,9.000000,17.000000,21.000000\n"
                                        "7.000000,18.000000,7.000000,21.000000,5.000000,13.000000,17.000000,8.000000\n"
                                        "18.000000,18.000000,15.000000,21.000000,18.000000,7.000000,8.000000,18.000000\n"
                                        "8.000000,14.000000,16.000000,10.000000,16.000000,17.000000,5.000000,19.000000\n"
                                        "12.000000,12.000000,8.000000,14.000000,19.000000,16.000000,5.000000,16.000000\n"
                                        "4.000000,11.000000,15.000000,8.000000,14.000000,11.000000,6.000000,10.000000\n"
                                        "19.000000,19.000000,2.000000,16.000000,4.000000,20.000000,12.000000,3.000000/\n"
                                        "0,0\n"
                                        "7,7\n");
    string path3 = solver3->getSolution("9.000000,3.000000,15.000000,20.000000,4.000000,12.000000,11.000000,5.000000\n"
                                        "4.000000,5.000000,8.000000,11.000000,4.000000,9.000000,17.000000,21.000000\n"
                                        "7.000000,18.000000,7.000000,21.000000,5.000000,13.000000,17.000000,8.000000\n"
                                        "18.000000,18.000000,15.000000,21.000000,18.000000,7.000000,8.000000,18.000000\n"
                                        "8.000000,14.000000,16.000000,10.000000,16.000000,17.000000,5.000000,19.000000\n"
                                        "12.000000,12.000000,8.000000,14.000000,19.000000,16.000000,5.000000,16.000000\n"
                                        "4.000000,11.000000,15.000000,8.000000,14.000000,11.000000,6.000000,10.000000\n"
                                        "19.000000,19.000000,2.000000,16.000000,4.000000,20.000000,12.000000,3.000000/\n"
                                        "0,0\n"
                                        "7,7\n");

    cout << path << endl;
    cout << searcher->getPathCost() << endl;
    cout << searcher->getNumberOfNodesEvaluated() << endl;
    cout << path1 << endl;
    cout << searcher1->getPathCost() << endl;
    cout << searcher1->getNumberOfNodesEvaluated() << endl;
    cout << path2 << endl;
    cout << searcher2->getPathCost() << endl;
    cout << searcher2->getNumberOfNodesEvaluated() << endl;
    cout << path3 << endl;
    cout << searcher3->getPathCost() << endl;
    cout << searcher3->getNumberOfNodesEvaluated() << endl;
*/
}
