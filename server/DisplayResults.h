//
// Created by oem on 1/16/23.
//

#ifndef EX4_AP_DISPLAYRESULTS_H
#define EX4_AP_DISPLAYRESULTS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"
#include "CsvReading.h"
#include "Minkowski.h"

class DisplayResults : public Command {
public:

/**
 * This function displays the results of the classification
 */
    void execute() override;
/**
 * This function is the constructor for the DisplayResults class.
 *
 * @param dio This is the DefaultIO object that is used to read in the data.
 * @param masterVectorTrain This is the vector of training data.
 * @param masterVectorTest This is the vector of test vectors.
 */
    DisplayResults(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest);


private:

    vector<VectorBase> *masterVectorTrain;

    vector<VectorBase> *masterVectorTest;
};

#endif //EX4_AP_DISPLAYRESULTS_H
