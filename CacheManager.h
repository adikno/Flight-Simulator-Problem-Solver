//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_CHACEMANAGER_H
#define UNTITLED14_CHACEMANAGER_H

#include <string>

using namespace std;

class CacheManager {

public:
    virtual bool isExist(string problem) = 0;

    virtual string getSulotion(string problem) = 0;

    virtual void saveSolution(string problem,string solution) = 0;



};
#endif //UNTITLED14_CHACEMANAGER_H
