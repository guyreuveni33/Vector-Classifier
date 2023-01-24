#ifndef EX3_AP_MANHATTAN_H
#define EX3_AP_MANHATTAN_H

#include "MasterDistance.h"

//A class that inherits from MasterDistance. It implements the algorithm function.
class Manhattan : public MasterDistance {
public:
/**
 * The function takes two vectors of doubles as parameters and returns the Manhattan distance between them
 *
 * @param v1 The first vector
 * @param v2 the vector of the test data
 *
 * @return The distance between the two vectors.
 */
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
