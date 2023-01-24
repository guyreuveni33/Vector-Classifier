#ifndef EX4_AP_DOWNLOADRESULTS_H
#define EX4_AP_DOWNLOADRESULTS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"
#include "CsvReading.h"
#include "Minkowski.h"

class DownloadResults : public Command {
public:
    void execute() override;

    DownloadResults(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest);


private:
    vector<VectorBase> *masterVectorTrain;
    vector<VectorBase> *masterVectorTest;
};

#endif //EX4_AP_DOWNLOADRESULTS_H
