#ifndef EX4_AP_SETALGO_H
#define EX4_AP_SETALGO_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"


class SetAlgo : public Command {
public:

/**
 * The function receives a string from the user, checks if it's valid, and if it is, it changes the KNN parameters
 */
    void execute() override;

    /**
 * The constructor for the SetAlgo class
 *
 * @param dio This is the DefaultIO object that is used to read and write files.
 * @param masterVectorTrain This is the training set.
 * @param masterVectorTest This is the vector of vectors that contains the test data.
 */
    SetAlgo(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest);

/**
 * @return The value of the private member variable k.
 */
    int getK();

/**
 * This function returns the distance metric used by the SetAlgo object.
 *
 * @return The distance metric.
 */
    string getDistanceMetric();

private:
    int k;
    string distanceMetric;
    vector<VectorBase> *masterVectorTrain;
    vector<VectorBase> *masterVectorTest;
};

#endif //EX4_AP_SETALGO_H
