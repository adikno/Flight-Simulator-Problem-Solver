//
// Created by michal on 12/28/18.
//

#ifndef UNTITLED14_FILECACHEMANGER_H
#define UNTITLED14_FILECACHEMANGER_H

#include <fstream>
#include <iostream>
#include "CacheManager.h"
#include <map>
#include "ParallelServer.h"


using  namespace std;
class FileCacheManager : public CacheManager{
    fstream cacheFile;
    map<string, string> solutions;

public:
    FileCacheManager() {
        cacheFile.open("cache.txt",fstream::in | fstream::out | fstream::app);
        string prob;
        string sol;
        while (getline(this->cacheFile, prob)) {
            getline(this->cacheFile, sol);
            solutions.insert(pair<string, string>(prob, sol));
        }
        cacheFile.close();
    }

    bool isExist(string problem) override;

    string getSulotion(string problem) override;

    void saveSolution(string problem,string solution) override;

    ~FileCacheManager() override = default;

};

#endif //UNTITLED14_FILECACHEMANGER_H
