//
// Created by adi on 08/01/19.
//

#include "StringReverser.h"

string StringReverser::getSolution(string problem) {
    for (int i = 0; i < problem.length() / 2; i++) {
        std::swap(problem[i], problem[problem.length() - i - 1]);
    }
    return problem;
}