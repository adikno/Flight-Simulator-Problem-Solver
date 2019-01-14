//
// Created by michal on 1/14/19.
//

#include "SolutionFile.h"

void SolutionFile::write(double cost, int evaluated) {
    if (solution.is_open()){
        string cost1 = to_string(cost);
        string evaluated1 = to_string(evaluated);
        this->solution<< cost1 + "," + evaluated1;
        this->solution<<"\n";
        solution.flush();

    }



}