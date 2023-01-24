#include "Canberra.h"


double Canberra::algorithm(vector<double> &v1, vector<double> &v2) {
    double sum = 0, upperSum, lowerSum, tempOne, tempTwo;
    for (int i = 0; i < v1.size(); i++) {
        upperSum = v1.at(i) - v2.at(i);
        if ((upperSum < 0)) {
            upperSum = upperSum * (-1);
        }
        tempOne = v1.at(i);
        tempTwo = v2.at(i);
        // This is to avoid division by zero.
        if (tempOne < 0)
            tempOne = tempOne * (-1);
        if (tempTwo < 0)
            tempTwo = tempTwo * (-1);
        if (tempOne == 0 && tempTwo == 0) {
            continue;
        }
        lowerSum = tempOne + tempTwo;
        sum = sum + (upperSum / lowerSum);
    }
    return sum;
}