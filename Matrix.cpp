//
// Created by michal on 1/9/19.
//

#include "Matrix.h"

State<Point>* Matrix::getInitialState() {
    return matrix[0][0];
}

State<Point>* Matrix::getGoalState() {
    return matrix[row - 1][col - 1];
}

list<State<Point>*> Matrix::getAllPossibleStates(State<Point>* s) {
    list<State<Point>*> adj;
    int x = s->getState()->getX();
    int y = s->getState()->getY();
    if (x - 1 >= 0 && matrix[x - 1][y]->getCost() > 0) {
        adj.push_back(matrix[x - 1][y]);
        //matrix[x - 1][y]->setParent(s);
    }
    if (x + 1 <= row - 1 && matrix[x + 1][y]->getCost() > 0) {
        adj.push_back(matrix[x + 1][y]);
        //matrix[x + 1][y]->setParent(s);
    }
    if (y - 1 >= 0 && matrix[x][y - 1]->getCost() > 0) {
        adj.push_back(matrix[x][y - 1]);
        //matrix[x][y - 1]->setParent(s);
    }
    if (y + 1 <= col - 1 && matrix[x][y + 1]->getCost() > 0) {
        adj.push_back(matrix[x][y + 1]);
        //matrix[x][y + 1]->setParent(s);
    }
    return adj;
}
