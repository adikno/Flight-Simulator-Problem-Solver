//
// Created by michal on 1/9/19.
//

#include "Matrix.h"

State<Point>* Matrix::getInitialState() {
    return this->initialState;
}

State<Point>* Matrix::getGoalState() {
    return this->goalState;
}

void Matrix::setValues(vector<vector<double> > vec) {
    int i = 0, j = 0;
    for (vector<double> line: vec) {
        for (double num: line) {
            auto *p = new Point(i, j);
            matrix[i][j] = new State<Point>(num, p);
            j++;
        }
        j = 0;
        i++;
    }
    //this->initialState = matrix[0][0];
    //this->goalState = matrix[row-1][col-1];
    this->current = matrix[0][0];
}

list<State<Point>*> Matrix::getAllPossibleStates(State<Point>* s, char type) {
    list<State<Point>*> adj;
    int x = s->getState()->getX();
    int y = s->getState()->getY();
    State<Point>* left = nullptr;
    State<Point>* right = nullptr;
    State<Point>* up = nullptr;
    State<Point>* down = nullptr;
    if (y - 1 >= 0 && matrix[x][y-1]->getCost() >= 0) {
        left = matrix[x][y-1];
    }
    if (y + 1 <= col - 1 && matrix[x][y+1]->getCost() >= 0) {
        right = matrix[x][y+1];
    }
    if (x - 1 >= 0 && matrix[x-1][y]->getCost() >= 0) {
        up = matrix[x-1][y];
    }
    if (x + 1 <= row - 1 && matrix[x+1][y]->getCost() >= 0) {
        down = matrix[x+1][y];
    }
        if (right != nullptr) {
            adj.push_back(right);
        }
        if (down != nullptr) {
            adj.push_back(down);
        }
        if (left != nullptr) {
            adj.push_back(left);
        }
        if (up != nullptr) {
            adj.push_back(up);
        }
    /*} else {
        if (down != nullptr) {
            adj.push_back(down);
        }
        if (right != nullptr) {
            adj.push_back(right);
        }
        if (left != nullptr) {
            adj.push_back(left);
        }
        if (up != nullptr) {
            adj.push_back(up);
        }
    }*/

    return adj;
}

void Matrix::setCurr(State<Point>* curr) {
    this->current = curr;
}
double Matrix::calculateHValue(State<Point>* cur)
{
    int xCur = cur->getState()->getX();
    int yCur = cur->getState()->getY();
    int xGoal = this->getGoalState()->getState()->getX();
    int yGoal = this->getGoalState()->getState()->getY();
    double disMan = abs (xCur - xGoal) +
                    abs (yCur - yGoal);
    double total = disMan + cur->getCost() + cur->getParent()->getDistance();
    //cur->setHeur(total);
    return total;

}

void Matrix::initDis() {
    for (int i = 0; i <row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            matrix[i][j]->initDis();
        }

    }


}

vector<vector<string>> Matrix::toString() {
    vector<vector<string>> all;
    vector<string> eachRow;
    for (int i = 0; i <row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            string x = to_string(int(matrix[i][j]->getCost()));
            eachRow.emplace_back(x);
        }
        all.emplace_back(eachRow);
        eachRow.clear();
    }
    return all;

}
