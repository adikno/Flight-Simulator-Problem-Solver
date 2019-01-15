//
// Created by michal on 1/14/19.
//

#ifndef UNTITLED14_GRAPHFILE_H
#define UNTITLED14_GRAPHFILE_H

#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;
class GraphFile {
    ofstream graph;
    string counter = "10";

public:
    GraphFile(){
        graph.open("graph.txt",std::ios_base::app);
        graph << counter;
        graph<<"\n";
    }
    void write(Matrix *matrix);

    ~GraphFile(){
        graph.close();
    }

};


#endif //UNTITLED14_GRAPHFILE_H
