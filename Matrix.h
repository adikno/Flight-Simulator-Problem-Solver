//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_MATRIX_H
#define UNTITLED14_MATRIX_H


#include <string>
#include <vector>
#include "Searchable.h"
#include "Point.cpp"


class Matrix : public Searchable<Point>{
    int row;
    int col;
    State<Point>* **matrix;
    State<Point>* initialState;
    State<Point>* goalState;
public:
    Matrix(int n, int m) {
        this->row = n;
        this->col = m;
        this->matrix = new State<Point>**[row];
        for(int i = 0; i < row; ++i)
            matrix[i] = new State<Point>*[col];
    }
    int getSize(){
        return row;
    }

    void setValues(vector<vector<double >> vec);
    State<Point>* getInitialState() override;

    State<Point>* getGoalState() override;

    list<State<Point>*> getAllPossibleStates(State<Point>* s, char type) override;

    void setCurr(State<Point>* curr) override;
    double calculateHValue(State<Point>* cur) override;

    ~Matrix() {
        for (int j = 0; j < row; j++) {
            for (int i = 0; i < row; ++i) {
                delete matrix[j][i];
            }
            delete matrix[j];
        }
        delete matrix;
    }
    vector<vector<string>> toString();

    void initDis() override;

    void setInitial(int i, int j) {
        this->initialState = matrix[i][j];
    }

    void setGoal(int i, int j) {
        this->goalState = matrix[i][j];
    }
};


#endif //UNTITLED14_MATRIX_H
