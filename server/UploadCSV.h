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


/**
 * This function reads in the CSV file and stores the data in a vector of VectorBase objects
 */
    void execute() override;


/**
 * This function is a constructor for the UploadCSV class.
 *
 * @param dio a pointer to the DefaultIO object that is used to read and write to the console.
 * @param masterVectorTrain This is the vector that will hold the training data.
 * @param masterVectorTest This is the vector that will hold the test data.
 */
    UploadCSV(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest);

private:
    vector<VectorBase> *masterVectorTrain;
    vector<VectorBase> *masterVectorTest;
};


#endif //EX4_AP_UPLOADCSV_H
