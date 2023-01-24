#ifndef EX3_AP_MINKOWSKI_H
#define EX3_AP_MINKOWSKI_H

#include "MasterDistance.h"

//This is a class that inherits from the MasterDistance class.
class Minkowski : public MasterDistance {
public:
/**
 * It takes two vectors of doubles, and returns the Minkowski distance between them
 *
 * @param v1 The first vector
 * @param v2 The vector that we are comparing to.
 *
 * @return The distance between two vectors.
 */
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
