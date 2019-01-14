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

    string getSolution(string problem) {
        //ignore first line !!
        vector<vector<double> > vec = explode(problem, ',');
        vector<double> first = vec.at(0);
        auto *matrix = new Matrix(first.size(), first.size());
        vec.erase(vec.end());
        vec.erase(vec.end());
        matrix->setValues(vec);
        Searchable<Point> *searchable = matrix;
        vector<State<Point> *> solution = searcher->search(searchable);
        string final = "";
        for (int i = 0; i < solution.size() - 1; i++) {
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
        final.erase(final.length() - 2, 2);
        delete matrix;
        return final;
    }

    vector<vector<double>> explode(string &s, const char &c) {
        vector<vector<double >> big;
        string buff{""};
        vector<double> small;
        for (auto n:s) {
            if (n == ' ' || (n == c && buff.empty())) {
                continue;
            }
            if (n == '\n') {
                if (buff[0] == '-') {
                    buff.erase(0, 1);
                    double num;
                     try {
                         num = -1 * stod(buff);
                     } catch (exception &e) {
                         cout << "a";
                     }
                    small.push_back(num);
                    big.push_back(small);
                    small.clear();
                    buff = "";
                } else {
                    double num;
                    try {
                        num = stod(buff);
                    } catch (exception &e) {
                        cout << "a";
                    }
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
                try {
                    num = -1 * stod(buff);
                } catch (exception &e) {
                    cout << "a";
                }
                small.push_back(num);
                buff = "";
                continue;
            }
            double num;
            try {
                num = stod(buff);
            } catch (exception &e) {
                cout << "a";
            }
            small.push_back(num);
            buff = "";
        }
        return big;
    }
};


#endif //UNTITLED14_SEARCHERSOLVER_H
