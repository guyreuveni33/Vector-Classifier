#include "SetAlgo.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"
#include "CsvReading.h"
#include "Minkowski.h"

class ClassifyData : public Command {
public:
    /**
 * The function iterates over all input vectors in masterVectorTest, and for each input vector, it iterates over all
 * vectors in masterVectorTrain, calculates the distance between the input vector and the train vector, and sets the
 * distance for the current train vector in masterVectorTrain. Then, it sorts masterVectorTrain by distance, finds the most
 * common class among the k closest vectors, and sets the class for the current input vector in masterVectorTest
 */
    void execute() override;

/**
 * This function takes in a DefaultIO object, a vector of VectorBase objects, a vector of VectorBase objects, and a SetAlgo
 * object.
 *
 * @param dio This is the DefaultIO object that is used to read in the data.
 * @param masterVectorTrain This is the vector of training data.
 * @param masterVectorTest This is the vector of test data.
 * @param algo The algorithm to use for classification.
 */
    ClassifyData(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest,
                 SetAlgo *algo);


private:
    vector<VectorBase> *masterVectorTrain;
    vector<VectorBase> *masterVectorTest;
    SetAlgo *algo;
};

#ifndef EX4_AP_CLASSIFYDATA_H
#define EX4_AP_CLASSIFYDATA_H

#endif //EX4_AP_CLASSIFYDATA_H
