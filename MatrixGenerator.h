//
// Created by michal on 1/14/19.
//

#ifndef UNTITLED14_MATRIXGENERATOR_H
#define UNTITLED14_MATRIXGENERATOR_H


#include "Matrix.h"

class MatrixGenerator {
    Matrix *matrix;
    int randSize;
public:
    MatrixGenerator(){
        srand (time(NULL));
        int num =  rand() % 20 + 1;
        this->randSize = num;
        this->matrix = new Matrix(num,num);

    }

    void create();

    Matrix* getMatrix(){
        return matrix;
    }
};



#endif //UNTITLED14_MATRIXGENERATOR_H
