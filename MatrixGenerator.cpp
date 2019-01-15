//
// Created by michal on 1/14/19.
//

#include <iostream>
#include "MatrixGenerator.h"
using namespace std;
void MatrixGenerator::create() {
    vector<vector<double> > vec;
    vector<double>  small;
    for (int j = 0; j < randSize ; ++j) {
        for (int i = 0; i < randSize ; ++i) {
            double num;
            num = rand() % 20 + 2;
            small.emplace_back(num);

        }
        vec.push_back(small);
        small.clear();
    }
    matrix->setValues(vec);
    matrix->setInitial(0,0);
    matrix->setGoal(this->randSize-1,this->randSize-1);
    //return matrix;
}
