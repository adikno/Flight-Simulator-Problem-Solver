//
// Created by michal on 12/30/18.
//
#include "ClientHandler.h"
#include "Solver.h"


class MyTestClientHandler: public ClientHandler{
    Solver *solver;
public:
    MyTestClientHandler(Solver *solver, CacheManager *cm): ClientHandler(cm) {
        solver = solver;
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