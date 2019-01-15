//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_SOLVER_H
#define UNTITLED14_SOLVER_H

#include <string>

using namespace std;

class Solver {

public:
    virtual string getSolution(string problem) = 0;
    virtual ~Solver() = default;
};
#endif //UNTITLED14_SOLVER_H
