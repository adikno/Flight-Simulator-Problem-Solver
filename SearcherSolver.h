//
// Created by adi on 10/01/19.
//

#ifndef UNTITLED14_SEARCHERSOLVER_H
#define UNTITLED14_SEARCHERSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "Matrix.h"
#include "Searchable.h"

class SearcherSolver : public Solver {
    Searcher<Point> *searcher;
public:
    SearcherSolver(Searcher<Point> *searcher1) {
        this->searcher = searcher1;
    }

    string getSolution(string problem) override {
        //ignore first line !!
        vector<vector<double> > vec = explode(problem, ',');
        vector<double> first = vec.at(0);
        auto *matrix = new Matrix(first.size(), vec.size() - 2);
        vector<double> temp = vec.at(vec.size() - 1);
        int goalX = temp.at(0);
        int goalY = temp.at(1);
        vec.erase(vec.end());
        temp = vec.at(vec.size() - 1);
        int initX = temp.at(0);
        int initY = temp.at(1);
        vec.erase(vec.end());
        matrix->setValues(vec);
        matrix->setGoal(goalX, goalY);
        matrix->setInitial(initX, initY);
        Searchable<Point> *searchable = matrix;
        vector<State<Point> *> solution = searcher->search(searchable);
        string final = "";
        for (unsigned long i = 0; i < solution.size() - 1; i++) {
            int x1 = solution.at(i)->getState()->getX();
            int y1 = solution.at(i)->getState()->getY();
            int x2 = solution.at(i + 1)->getState()->getX();
            int y2 = solution.at(i + 1)->getState()->getY();
            if (y1 < y2) {
                final += "Right, ";
                continue;
            }
            if (y1 > y2) {
                final += "Left, ";
                continue;
            }
            if (x1 < x2) {
                final += "Down, ";
                continue;
            }
            if (x1 > x2) {
                final += "Up, ";
                continue;
            }
        }
     //   delete matrix;
        final.erase(final.length() - 2, 2);

        return final;
    }

    vector<vector<double>> explode(string &s, const char &c) {
        vector<vector<double >> big;
        string buff{""};
        vector<double> small;
        try {
            for (auto n:s) {
                if (n == ' ' || (n == c && buff.empty())) {
                    continue;
                }
                if (n == '\n') {
                    if (buff[0] == '-') {
                        buff.erase(0, 1);
                        double num;
                        num = -1 * stod(buff);
                        small.push_back(num);
                        big.push_back(small);
                        small.clear();
                        buff = "";
                    } else {
                        double num;
                        num = stod(buff);
                        small.push_back(num);
                        big.push_back(small);
                        small.clear();
                        buff = "";
                        continue;
                    }
                }
                if (n != c) {
                    buff += n;
                    continue;
                }
                if (buff[0] == '-') {
                    buff.erase(0, 1);
                    double num;
                    num = -1 * stod(buff);
                    small.push_back(num);
                    buff = "";
                    continue;
                }
                double num;
                num = stod(buff);
                small.push_back(num);
                buff = "";
            }
        } catch(exception &e) {}
        return big;
    }

    ~SearcherSolver() override {
        delete searcher;
    }
};


#endif //UNTITLED14_SEARCHERSOLVER_H
