//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_DFS_H
#define UNTITLED14_DFS_H


#include "Searcher.h"

template <class T>
class DFS : public Searcher<T> {
private:
    int evaluated;

public:
    DFS(){
        evaluated =0;
    }
    vector<State<T>*> search(Searchable<T> searchable) override {
        searchable.setCurrVisited();
        vector<State<T>*> trace;
        this->helpSearch(searchable, searchable.getInitialState(), trace);
        return trace;
    }

    void helpSearch(Searchable<T> &searchable, State<T> &curr, vector<State<T>*> &trace) {
        curr.setVisited();
        trace.push_back(curr);
        evaluated++;
        list<State<T>> succerssors = searchable.getAllPossibleStates(curr);
        for (State<T> state : succerssors) {
            bool visited = state.getVisited();
            if (!visited) {
                helpSearch(searchable, state, trace);
            }
        }
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }
};





#endif //UNTITLED14_DFS_H
