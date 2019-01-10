//
// Created by michal on 1/9/19.
//

#ifndef UNTITLED14_BESTFIRSTSEARCH_H
#define UNTITLED14_BESTFIRSTSEARCH_H


#include "Searcher.h"
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    int evaluated;
    double pathCost;
    class Cmp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getDistance()) > (right->getDistance());
        }
    };

public:
    BestFirstSearch() {
        evaluated = 0;
        pathCost =0;
    }

    priority_queue<State<T>*,vector<State<T>*>,Cmp> updateQueue(priority_queue<State<T>*, vector<State<T>*>, Cmp> &queueOpen) {
        priority_queue<State<T>*,vector<State<T>*>,Cmp> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
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

    vector<State<T>*> search(Searchable<T>* searchable) override {
        priority_queue<State<T>*, vector<State<T>*>, Cmp> openList;
        openList.push(searchable->getInitialState());
        unordered_set<State<T>*> closed;
        vector<State<T>*> path;
        evaluated++;
        while (!openList.empty()) {
            State<T>* n = openList.top();
            openList.pop();
            closed.insert(n);
            if(n->getParent() != NULL){
                n->setDistance(n->getParent()->getDistance());
            }

            if (n->equals(searchable->getGoalState())) {
                path.push_back(n);
                while (!n->equals(searchable->getInitialState())) {
                    path.push_back(n->getParent());
                    pathCost += n->getCost();
                    n = n->getParent();
                }
                pathCost += n->getCost();
                vector<State<T>*> back;
                for (int i = path.size() - 1; i >= 0 ; i--) {
                    back.push_back(path.at(i));
                }
                return back;
            }
            list<State<T>*> adjacent = searchable->getAllPossibleStates(n, 'b');
            for (State<T>* adj : adjacent) { ;
                bool exist = isExist(openList, adj);
                if (!exist && closed.count(adj) != 1) {
                    adj->setParent(n);
                    openList.push(adj);
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
        return path;
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }

    double getPathCost() override {
        return pathCost;
    }


};


#endif //UNTITLED14_BESTFIRSTSEARCH_H
