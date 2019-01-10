//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_SEARCHER_H
#define UNTITLED14_SEARCHER_H

#include <vector>
#include "Searchable.h"

template <class T>
        class Searcher{
public:
// the search method
    virtual vector<State<T>> search (Searchable<T> searchable) = 0;
// get how many nodes were evaluated by the algorithm
    virtual int getNumberOfNodesEvaluated() = 0;

};
#endif //UNTITLED14_SEARCHER_H
