//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_SEARCHABLE_H
#define UNTITLED14_SEARCHABLE_H

#include "State .h"
#include <list>
using namespace std;
template <class T>
class Searchable{
    State<T>* current;
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) =0;
    virtual State<T>* getCurrent() {
        return current;
    }
    virtual void setCurrVisited() {
        current->setVisited();
    }
    virtual bool getCurrVisited() {
        return current->getVisited();
    }
};
#endif //UNTITLED14_SEARCHABLE_H
