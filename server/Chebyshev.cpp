#include "Chebyshev.h"


double Chebyshev::algorithm(vector<double> &v1, vector<double> &v2) {
    double max, temp;
    max = v1.at(0) - v2.at(0);
    if ((max < 0)) {
        max = max * (-1);
    }
    for (int i = 1; i < v1.size(); ++i) {
        temp = (v1.at(i) - v2.at(i));
        if (temp < 0)
            temp = temp * (-1);
        if (temp > max)
            max = temp;
    }
    return max;
}