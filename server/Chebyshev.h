#ifndef EX3_AP_CHEBYSHEV_H
#define EX3_AP_CHEBYSHEV_H

#include "MasterDistance.h"

//A class that inherits from the MasterDistance class.
class Chebyshev : public MasterDistance {
public:
/**
 * The function takes two vectors of the same size and returns the maximum difference between the corresponding elements
 * of the two vectors
 *
 * @param v1 the vector of the first image
 * @param v2 the vector of the query image
 *
 * @return The maximum difference between the two vectors.
 */
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
