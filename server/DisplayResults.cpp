//
// Created by oem on 1/16/23.
//

#include "DisplayResults.h"
#include "SetAlgo.h"
#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "CsvReading.h"
#include "Minkowski.h"
#include "ClassifyData.h"


DisplayResults::DisplayResults(DefaultIO *dio, vector<VectorBase> &masterVectorTest) {
    this->dio = dio;
    this->description = "display results";
    this->masterVectorTest = masterVectorTest;
}


void ClassifyData::execute() {
    string vectorSize = to_string(this->masterVectorTest.size());
    this->dio->write(vectorSize);
    int loopSize = (int)this->masterVectorTest.size();
    int i;
    for(i = 0; i < loopSize; i++) {
        string resultDisplay = to_string(i+1) + "  " + this->masterVectorTest.at(i).getStr();
        this->dio->write(resultDisplay);
    }
}