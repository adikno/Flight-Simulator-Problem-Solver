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

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    int evaluated;

    class Compere {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getCost()) < (right->getCost());
        }
    };

public:
    BestFirstSearch() {
        evaluated = 0;
    }

    priority_queue<State<T>*> updateQueue(priority_queue<State<T>*> &queueOpen) {
        priority_queue<State<T>*> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
    }

    vector<State<T>> search(Searchable<T> searchable) override {
        priority_queue<State<T>*, vector<State<T>*>, Compere> openList;
        openList.push(searchable.getInitialState());
        unordered_set<State<T>> closed;
        vector<State<T>> path;
        evaluated++;
        while (!openList.empty()) {
            State<T>* n = openList.top();
            openList.pop();
            closed.insert(n);
            if (n->equals(searchable.getGoalState())) {
                while (!n->Equal(searchable.getInitialState())) {
                    path.push_back(n->getParent().getState());
                    n = n->getParent();
                }
                reverse(path.begin(),path.end());
                return path;
            }
            list<State<T>*> adjacent = searchable.getAllPossibleStates(n);
            for (State<T>* adj : adjacent) { ;
                bool exist = false;
                for (list<State<T>*> s: openList) {
                    if (s == adj) {
                        exist = true;
                        break;
                    }
                }
                if (!exist && closed.count(adj) != 0) {
                    adj->setParent(n);
                    openList.push(adj);
                    evaluated++;
                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    bool inOpen = false;
                    for (list<State<T>*> s: openList) {
                        if (s == adj) {
                            inOpen = true;
                            break;
                        }
                    }
                    if (!inOpen) {
                        openList.push(adj);
                        evaluated++;
                    } else {
                        adj->setDistance(n->getDistance() + adj->getCost());
                        adj->setParent(n);
                        openList = updateQueue(openList);
                    }
                }
            }
        }
        return path;
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }


};


#endif //UNTITLED14_BESTFIRSTSEARCH_H
