#ifndef EX3_AP_CANBERRA_H
#define EX3_AP_CANBERRA_H
#include "MasterDistance.h"

//A class that inherits from the MasterDistance class.
class Canberra : public MasterDistance {
public:
/**
 * The function takes two vectors as input and returns the sum of the canberra distance between the two vectors
 *
 * @param v1 The first vector
 * @param v2 The vector of the current document
 *
 * @return The Canberra distance between two vectors.
 */
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
