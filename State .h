//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_STATE_H
#define UNTITLED14_STATE_H

#include <list>

using namespace std;
template <class T>
class State{
    T* state;
    State<T>* parent;
    double cost;
    int distance;
    bool visited = false;
public:

    State(double cost, T *state){
        this->cost =cost;
        this->distance = cost;
        this->parent = nullptr;
        this->state = state;
    }
    T* getState(){
        return this->state;
    }
    State<T>* getParent(){
        return this->parent;
    }
    void setParent( State<T>* dad){
        this->parent = dad;
    }
    bool equals(State<T> *s){
        return this == s;
    }
    int getDistance() {
        return distance;
    }
    void setVisited() {
        visited = true;
    }
    bool getVisited() {
        return visited;
    }
    void setCost(double x){
        this->cost = x;
    }
    double getCost(){
        return this->cost;
    }
    void setDistance(int d) {
        this->distance += d;
    }

};
#endif //UNTITLED14_STATE_H
