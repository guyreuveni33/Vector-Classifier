//
// Created by oem on 1/16/23.
//

#include "SetAlgo.h"
#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "CsvReading.h"
#include "Minkowski.h"
#include "ClassifyData.h"

ClassifyData::ClassifyData(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest,
                           int k, string distanceMetric) {
    this->dio = dio;
    this->description = "classify data";
    this->masterVectorTrain = masterVectorTrain;
    this->masterVectorTest = masterVectorTest;
    this->k = k;
    this->distanceMetric = distanceMetric;

}



void ClassifyData::execute() {
    if (this->masterVectorTrain->empty() || this->masterVectorTest->empty()) {
        string emptyMessage = "please upload data";
        this->dio->write(emptyMessage);
    } else {
        // Iterate over all input vectors in masterVectorTest
        int i, j;
        for (i = 0; i < masterVectorTest->size(); i++) {
            vector<double> inputVector = (*masterVectorTest)[i].getVector();
            // Iterate over all vectors in masterVectorTrain
            for (j = 0; j < masterVectorTrain->size(); j++) {
                vector<double> trainVector = (*masterVectorTrain)[j].getVector();
                double distance = distanceCalculator(this->distanceMetric, inputVector, trainVector);
                // Set distance for the current train vector in masterVectorTrain
                (*masterVectorTrain)[j].setAlgoDistance(distance);
            }
            // Sort masterVectorTrain by distance
            sortVector(*masterVectorTrain);
            // Find the most common class among the k closest vectors
            string most_common = highestOccurrence(k, *masterVectorTrain);
            // Set the class for the current input vector in masterVectorTest
            (*masterVectorTest)[i].setStr(most_common);
            //cout<<most_common<<endl;
        }
        string complete = "classifying data complete";
        this->dio->write(complete);
    }
}
