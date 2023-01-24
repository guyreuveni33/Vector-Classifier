#ifndef EX3_AP_EUCLIDEAN_H
#define EX3_AP_EUCLIDEAN_H
#include "MasterDistance.h"

//This is a class that inherits from the MasterDistance class. It has a function called algorithm that takes two
//vectors and returns a double.
class Euclidean : public MasterDistance {
public:
/**
 * It takes two vectors of doubles, subtracts the corresponding elements, squares the result, and then sums the squares.
 * The sum is then square rooted to get the Euclidean distance
 *
 * @param v1 The first vector
 * @param v2 The vector that we are comparing to.
 *
 * @return The distance between the two vectors.
 */
     double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
