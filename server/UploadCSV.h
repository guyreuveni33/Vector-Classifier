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
  * This function reads in the CSV files from the user and stores them in a vector of VectorBase objects
  */
    void execute() override;

    /**
 * This function is a constructor for the UploadCSV class
 *
 * @param dio this is the DefaultIO object that is used to read and write to the console.
 * @param masterVectorTest This is the vector that will hold the test data.
 * @param masterVectorTrain This is the vector that will hold the training data.
 */
    UploadCSV(DefaultIO *dio,vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest);
    /**
 * This function returns a pointer to the masterVectorTest vector.
 *
 * @return A pointer to the masterVectorTest vector.
 */
private:
    vector<VectorBase> *masterVectorTrain;
    vector<VectorBase> *masterVectorTest;
};


#endif //EX4_AP_UPLOADCSV_H
