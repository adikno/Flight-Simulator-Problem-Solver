//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_SOLVER_H
#define UNTITLED14_SOLVER_H

#include <string>

using namespace std;

template <class P, class S>
class Solver {

public:
    virtual string getSolution(string problem) = 0;
};
#endif //UNTITLED14_SOLVER_H
