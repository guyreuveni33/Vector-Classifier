#include "Manhattan.h"


double Manhattan::algorithm(vector<double> &v1, vector<double> &v2) {
    int i;
    double sum = 0;
    for (i = 0; i < v1.size(); i++) {
        double temp = v1.at(i) - v2.at(i);
        if (temp < 0) {
            temp = temp * (-1);
        }
        sum += pow(temp, 1);
    }
    double distance = pow(sum, 1.0 / (double) 1);
    return distance;
}