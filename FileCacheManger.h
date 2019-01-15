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
    ofstream cacheFile;

    map<string, string> solutions;
public:
    FileCacheManager() {
        ifstream myfile ("cache.txt");

        if(myfile.is_open()){
            string prob;
            string allMatrix;
            string sol;
            while (getline(myfile, prob)) {
                if(prob.at(0) != 'R' && prob.at(0) != 'U' && prob.at(0) != 'L' && prob.at(0) != 'D'){
                    allMatrix += prob;
                    allMatrix += "\n";
                    continue;
                }
                //getline(myfile, prob);
                solutions.insert(pair<string, string>(allMatrix, prob));
            }
            //myfile.close();
        }



    }

    bool isExist(string problem) override;

    string getSulotion(string problem) override;

    void saveSolution(string problem,string solution) override;

    ~FileCacheManager() override{
        ofstream cache ("cache.txt");
        if (cache.is_open()) {
            for (std::map<string, string>::iterator it = solutions.begin(); it != solutions.end(); ++it) {
                cache << it.operator*().first;
                cache << it.operator*().second + "\n";
                cache.flush();
                cache.close();

            }
        }
        cache.close();
    }


};

#endif //UNTITLED14_FILECACHEMANGER_H
