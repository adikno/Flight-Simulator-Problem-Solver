//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_BFS_H
#define UNTITLED14_BFS_H


#include <vector>
#include <unordered_set>
#include "Searcher.h"

template <class T>
class BFS : public Searcher<T>{
private:
    int evaluated;

public:
    BFS(){
        evaluated =0;
    }
    vector<State<T>> search(Searchable<T> searchable) override{
        list<State<T>> openList;
        openList.push_back(searchable.getInitialState());
        evaluated++;
        searchable.setCurrVisited();
        vector<State<T>> trace;
        while (openList.size() > 0){
            State<T> n = openList.front();
            trace.push_back(n);
            openList.pop_front();
            if(n.equals(searchable.getGoalState())){
                return trace();
            }
            list<State<T>> succerssors = searchable.getAllPossibleStates(n);
            for (State<T> state : succerssors){
                bool visited = state.getVisited();
                if(!visited) {
                    state.setVisited();
                    openList.push_back(state);
                    evaluated++;
                }
            }
        }
        return nullptr;



    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }



};


#endif //UNTITLED14_BFS_H
