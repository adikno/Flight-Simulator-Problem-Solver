//
// Created by michal on 12/28/18.
//

#include "FileCacheManger.h"

bool FileCacheManager:: isExist(string problem)  {
    string solution;
    std::map<string,string>::iterator it;

    try{
        pthread_mutex_lock(&mutexMap);
        it = solutions.find(problem);
        if ( it == solutions.end() ) {
            pthread_mutex_unlock(&mutexMap);
            return false;
        } else {
            pthread_mutex_unlock(&mutexMap);
            return true;
        }

    } catch (exception &e){
        pthread_mutex_unlock(&mutexMap);
        return false;
    }
}

string FileCacheManager::getSulotion(string problem)  {
    string solution;
    try{
        pthread_mutex_lock(&mutexMap);
        solutions.at(problem) = solution;
        pthread_mutex_unlock(&mutexMap);
        return solution;
    }catch (exception &e){
        pthread_mutex_unlock(&mutexMap);
        return nullptr;
    }
}

void FileCacheManager::saveSolution(string problem ,string solution)  {
    pthread_mutex_lock(&mutexMap);
    solutions.insert(pair<string, string>(problem, solution));
    pthread_mutex_unlock(&mutexMap);
    /*
    pthread_mutex_lock(&mutexFile);
    this->cacheFile.open("cache.txt");
    this->cacheFile << problem + "\n";
    this->cacheFile << solution + "\n";
    this->cacheFile.flush();
    this->cacheFile.close();
    pthread_mutex_unlock(&mutexFile);
     */

}

