//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_MATRIX_H
#define UNTITLED14_MATRIX_H


#include "Searchable.h"
#include "Point.cpp"


class Matrix : public Searchable<Point>{
    int row;
    int col;
    State<Point>* **matrix;
public:
    Matrix(int n, int m) {
        this->row = n;
        this->col = m;
        this->matrix = new State<Point>**[row];
        for(int i = 0; i < row; ++i)
            matrix[i] = new State<Point>*[col];
    }
    State<Point>* getInitialState() override;

    State<Point>* getGoalState() override;

    list<State<Point>*> getAllPossibleStates(State<Point>* s) override;

};


#endif //UNTITLED14_MATRIX_H
