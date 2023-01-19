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
    void execute() override;

    DisplayResults(DefaultIO *dio, vector<VectorBase> &masterVectorTrain, vector<VectorBase> &masterVectorTest);
    vector<VectorBase>* getMasterVectorTrain() override;
    vector<VectorBase>* getMasterVectorTest() override;

private:
    vector<VectorBase> masterVectorTrain;
    vector<VectorBase> masterVectorTest;
};

#endif //EX4_AP_DISPLAYRESULTS_H
