//
// Created by michal on 1/14/19.
//

#include "MatrixGenerator.h"

void MatrixGenerator::create() {

    vector<vector<double> > vec;
    vector<double>  small;
    for (int j = 0; j < randSize ; ++j) {
        for (int i = 0; i < randSize ; ++i) {
            double num;
            num = rand() % 20 + 1;
            small.emplace_back(num);

        }
        vec.push_back(small);
        small.clear();
    }
    matrix->setValues(vec);
    //return matrix;
}
