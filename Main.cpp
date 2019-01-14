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
//#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"
#include "MatrixHandler.h"
#include "BestFirstSearch.h"
#include "ParallelServer.h"
#include "MatrixGenerator.h"
#include "GraphFile.h"
#include "SolutionFile.h"

pthread_mutex_t mutex;
pthread_mutex_t mutexFile;
int main(int argc, char *argv[]) {


    Searcher<Point> *searcher = new BestFirstSearch<Point>();
    Searcher<Point> *searcher1 = new DFS<Point>();
    Searcher<Point> *searcher2 = new BFS<Point>();
    Searcher<Point> *searcher3 = new AStar<Point>();
    for (int i = 0; i< 1; i++){
        GraphFile *graphFile = new GraphFile();
        SolutionFile *solutionFile = new SolutionFile();
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
    pthread_mutex_init(&mutex, nullptr);
    pthread_mutex_init(&mutexFile, nullptr);

    auto *solver = new SearcherSolver(searcher);
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MatrixHandler(solver, cacheManager);
    /*
    server_side::Server *server = new server_side::ParallelServer();
    server->open(atoi(argv[1]), clientHandler);
    //while(true);

    auto *solver2 = new SearcherSolver(searcher2);
    auto *solver3 = new SearcherSolver(searcher3);
    string path1 = solver->getSolution("4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8\n"
                                       " 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4\n"
                                       " 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7\n"
                                       " 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7\n"
                                       " 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1\n"
                                       " 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9\n"
                                       " 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8\n"
                                       "10, 8, 0, 2, 3, 8, 0,10,10, 2, 7\n"
                                       " 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1\n"
                                       " 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1\n"
                                       " 5,10, 1,10, 7, 7, 3,10, 8, 0, 6\n"
                                       "1,1\n"
                                       "1,1\n");
    string path2 = solver2->getSolution(" 4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8\n"
                                        " 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4\n"
                                        " 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7\n"
                                        " 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7\n"
                                        " 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1\n"
                                        " 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9\n"
                                        " 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8\n"
                                        "10, 8, 0, 2, 3, 8, 0,10,10, 2, 7\n"
                                        " 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1\n"
                                        " 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1\n"
                                        " 5,10, 1,10, 7, 7, 3,10, 8, 0, 6\n"
                                        "1,1\n"
                                        "1,1\n");
    string path3 = solver3->getSolution("4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8\n"
                                        " 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4\n"
                                        " 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7\n"
                                        " 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7\n"
                                        " 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1\n"
                                        " 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9\n"
                                        " 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8\n"
                                        "10, 8, 0, 2, 3, 8, 0,10,10, 2, 7\n"
                                        " 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1\n"
                                        " 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1\n"
                                        " 5,10, 1,10, 7, 7, 3,10, 8, 0, 6\n"
                                        "1,1\n"
                                        "1,1\n");

    cout << path1 << endl;
    cout << searcher->getPathCost() << endl;
    cout << searcher->getNumberOfNodesEvaluated() << endl;
    cout << path2 << endl;
    cout << searcher2->getPathCost() << endl;
    cout << searcher2->getNumberOfNodesEvaluated() << endl;
    cout << path3 << endl;
    cout << searcher3->getPathCost() << endl;
    cout << searcher3->getNumberOfNodesEvaluated() << endl;
      */

}