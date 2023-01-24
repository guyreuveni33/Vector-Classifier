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
/**
 * It sends the classified data to the client in order to create a document of the classification data.
 */
    void execute() override;

/**
 * This function downloads the results of the training and testing vectors, this is the cotr.
 *
 * @param dio This is the DefaultIO object that we created in the previous step.
 * @param masterVectorTrain This is the vector of training data.
 * @param masterVectorTest This is the vector of test vectors that we will be using to test our model.
 */
    DownloadResults(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest);


private:
    vector<VectorBase> *masterVectorTrain;
    vector<VectorBase> *masterVectorTest;
};

#endif //EX4_AP_DOWNLOADRESULTS_H
