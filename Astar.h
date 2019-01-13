//
// Created by michal on 1/11/19.
//

#ifndef UNTITLED14_ASTAR_H
#define UNTITLED14_ASTAR_H

#include "Searcher.h"
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include "Point.cpp"
template <class T>
class Astar :  public Searcher<Point> {
private:
    int evaluated;
    double pathCost;
    class Cmp {
    public:
        bool operator()(State<Point>* left, State<Point>* right) {
            return (left->getHeur()) > (right->getHeur());
        }
    };

public:
    Astar() {
        evaluated = 0;
        pathCost = 0;
    }
    double calculateHValue(State<Point>* cur,Searchable<Point> *searchable)
    {
        State<T>* goal = searchable->getGoalState();
        int xCur = cur->getState()->getX();
        int yCur = cur->getState()->getY();
        int xGoal = searchable->getGoalState()->getState()->getX();
        int yGoal = searchable->getGoalState()->getState()->getY();
        double disMan = abs (xCur - xGoal) +
                abs (yCur - yGoal);
        double total = disMan + cur->getCost() + cur->getParent()->getDistance();
        //cur->setHeur(total);
        return total;

    }
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Cmp> open, State<T> *state) {
        while (!open.empty()) {
            if (state->equals(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;
    }
    vector<State<T> *> search(Searchable<T> *searchable) override {

        priority_queue<State<T> *, vector<State<T> *>, Cmp> openList;
        openList.push(searchable->getInitialState());
        unordered_set<State<T> *> closed;
        vector<State<T> *> path;
        // Put the starting cell on the open list and set its
        // 'f' as 0
        openList.insert(searchable->getInitialState());
        evaluated++;

        // We set this boolean value as false as initially
        // the destination is not reached.
        bool foundDest = false;

        while (!openList.empty()) {
            State<T> *n = openList.top();

            // Remove this vertex from the open list
            openList.pop();

            // Add this vertex to the closed list
            n->setVisited();
            closed.insert(n);

            if (n->equals(searchable->getGoalState())) {
                path.push_back(n);
                while (!n->equals(searchable->getInitialState())) {
                    path.push_back(n->getParent());
                    pathCost += n->getCost();
                    n = n->getParent();
                }
                pathCost += n->getCost();
                vector<State<T> *> back;
                for (unsigned long i = path.size() - 1; i >= 0; i--) {
                    back.push_back(path.at(i));
                }
                return back;
            }
            list<State<T> *> adjacent = searchable->getAllPossibleStates(n, 'b');
            for (State<T> *adj : adjacent) {
                bool exist = isExist(openList, adj);
                if (!exist && closed.count(adj) != 1) {
                    adj->setParent(n);
                    adj->setHeur(this->calculateHValue(adj, searchable));
                    openList.push(adj);
                    adj->setDistance(n->getDistance() + adj->getCost());

                    //openList = updateQueue(openList);
                    evaluated++;

                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    bool inOpen = isExist(openList, adj);
                    //if (!inOpen) {
                    //openList.push(adj);
                    //evaluated++;
                    //} else {
                    adj->setDistance(n->getDistance() + adj->getCost());
                    adj->setParent(n);
                    openList = updateQueue(openList);
                    //}
                }
            }
        }
    }
               // return vector<State<T> *>();


        int getNumberOfNodesEvaluated()
        override{
                return 0;
        }

        double getPathCost()
        override{
                return 0;
        }


};


#endif //UNTITLED14_ASTAR_H
