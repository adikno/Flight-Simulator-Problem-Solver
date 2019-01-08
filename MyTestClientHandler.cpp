//
// Created by michal on 12/30/18.
//
#include "ClientHandler.h"
#include "Solver.h"


class MyTestClientHandler: public ClientHandler{
    Solver<class P, class S> *solver;
public:
    MyTestClientHandler(Solver<class P, class S> *solver1, CacheManager *cm): ClientHandler(cm) {
        this->solver = solver1;
    }
    void handleClient(ostream &output, istream &input) override {
        string line;
        string solution;
        while (getline(input, line)) {
            if (cm->isExist(line)){
                solution = cm->getSulotion(line);
            } else {
                solution = solver->getSolution(line);
                cm->saveSolution(line,solution);
            }
            output << solution ;
            output.flush();
        }
    }

};