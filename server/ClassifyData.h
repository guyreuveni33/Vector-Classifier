//
// Created by oem on 1/16/23.
//

#include "SetAlgo.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"
#include "CsvReading.h"
#include "Minkowski.h"

class ClassifyData : public Command {
public:
    void execute() override;
    ClassifyData(DefaultIO *dio,vector<VectorBase> *masterVectorTrain,vector<VectorBase> *masterVectorTest,
                 SetAlgo *algo);


private:
    vector<VectorBase> *masterVectorTrain;
    vector<VectorBase> *masterVectorTest;
    SetAlgo *algo;
};

#ifndef EX4_AP_CLASSIFYDATA_H
#define EX4_AP_CLASSIFYDATA_H

#endif //EX4_AP_CLASSIFYDATA_H
