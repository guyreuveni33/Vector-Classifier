#ifndef EX4_AP_UPLOADCSV_H
#define EX4_AP_UPLOADCSV_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"

#include "CsvReading.h"
#include "Minkowski.h"

class UploadCSV : public Command {
public:
    void execute() override;
    UploadCSV(DefaultIO *dio,vector<VectorBase> &masterVectorTest,vector<VectorBase> &masterVectorTrain);
    vector<VectorBase> getMasterVectorTrain()override;
    vector<VectorBase> getMasterVectorTest()override;
private:
    vector<VectorBase> masterVectorTrain;
    vector<VectorBase> masterVectorTest;
};


#endif //EX4_AP_UPLOADCSV_H
