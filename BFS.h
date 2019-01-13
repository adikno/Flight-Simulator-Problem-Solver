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
    double pathCost;

public:
    BFS(){
        evaluated =0;
        pathCost = 0;
    }
    vector<State<T>*> search(Searchable<T>* searchable) override{
        list<State<T>*> openList;
        openList.push_back(searchable->getInitialState());
        evaluated++;
        searchable->setCurrVisited();
        vector<State<T>*> trace;
        while (openList.size() > 0){
            State<T>* n = openList.front();
            openList.pop_front();
            if(n->equals(searchable->getGoalState())){
                evaluated++;
                while (n->getParent() != nullptr) {
                    trace.push_back(n);
                    pathCost += n->getCost();
                    n = n->getParent();
                }
                pathCost += n->getCost();
                trace.push_back(n);
                vector<State<T>*> back;
                for (int i = trace.size() - 1; i >= 0 ; i--) {
                    back.push_back(trace.at(i));
                }
                return back;
            }
            list<State<T>*> succerssors = searchable->getAllPossibleStates(n, 'b');
            for (State<T>* state : succerssors){
                bool visited = state->getVisited();
                if(!visited) {
                    state->setVisited();
                    state->setParent(n);
                    openList.push_back(state);
                    evaluated++;
                    searchable->setCurr(state);
                }
            }
        }
        //return nullptr;
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }

    double getPathCost() override {
        return pathCost;
    }



};


#endif //UNTITLED14_BFS_H
