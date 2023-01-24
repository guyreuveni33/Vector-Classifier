#include "SetAlgo.h"
#include "Command.h"
#include <map>
#include "CsvReading.h"
#include "Minkowski.h"
#include "ClassifyData.h"
#include <iostream>

ClassifyData::ClassifyData(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest,
                           SetAlgo *algo) {
    this->dio = dio;
    this->description = "classify data";
    this->masterVectorTrain = masterVectorTrain;
    this->masterVectorTest = masterVectorTest;
    this->algo = algo;

}


void ClassifyData::execute() {
    if (this->masterVectorTrain->empty() || this->masterVectorTest->empty()) {
        string emptyMessage = "please upload data";
        this->dio->write(emptyMessage);
    }
    else if(kCheck(this->algo->getK(), *this->masterVectorTrain) == 0){
        string emptyMessage = "K is invalid";
        this->dio->write(emptyMessage);
    }
    else {
        // Iterate over all input vectors in masterVectorTest
        int i, j;
        for (i = 0; i < masterVectorTest->size(); i++) {
            vector<double> inputVector = (*masterVectorTest)[i].getVector();
            // Iterate over all vectors in masterVectorTrain
            for (j = 0; j < masterVectorTrain->size(); j++) {
                vector<double> trainVector = (*masterVectorTrain)[j].getVector();
                double distance = distanceCalculator(this->algo->getDistanceMetric(), inputVector, trainVector);
                // Set distance for the current train vector in masterVectorTrain
                (*masterVectorTrain)[j].setAlgoDistance(distance);
            }
            // Sort masterVectorTrain by distance
            sortVector(*masterVectorTrain, this->algo->getK());
            // Find the most common class among the k closest vectors
            string most_common = highestOccurrence(this->algo->getK(), *masterVectorTrain);
            // Set the class for the current input vector in masterVectorTest
            (*masterVectorTest)[i].setStr(most_common);
            //cout<<most_common<<endl;
        }
        string complete = "classifying data complete";
        this->dio->write(complete);
    }
}
