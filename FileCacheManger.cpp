//
// Created by michal on 12/28/18.
//

#include "FileCacheManger.h"

bool FileCacheManager:: isExist(string problem)  {
    string solution;
    try{
        solutions.at(problem);
        return true;
    }catch (exception &e){
        return false;
    }
}

string FileCacheManager::getSulotion(string problem)  {
    string solution;
    try{
        solutions.at(problem) = solution;
        return solution;
    }catch (exception &e){
        return nullptr;
    }
}

void FileCacheManager::saveSolution(string problem ,string solution)  {
    this->cacheFile.open("cache.txt");
    this->cacheFile << problem + "\n";
    this->cacheFile << solution + "\n";
    this->cacheFile.close();

}
