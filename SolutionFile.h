//
// Created by michal on 1/14/19.
//

#ifndef UNTITLED14_SOLUTIONFILE_H
#define UNTITLED14_SOLUTIONFILE_H



#include <iostream>
#include <fstream>

using namespace std;
class SolutionFile {

    ofstream solution;

public:
    SolutionFile(){
        solution.open("solution.txt");
    }

    void write(double cost , int evaluated);

    ~SolutionFile(){
        solution.close();
    }



};


#endif //UNTITLED14_SOLUTIONFILE_H
