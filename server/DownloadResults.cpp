//
// Created by oem on 1/16/23.
//

#include "DownloadResults.h"

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


DownloadResults::DownloadResults(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest) {
    this->dio = dio;
    this->description = "download results";
    this->masterVectorTest = masterVectorTest;
    this->masterVectorTrain = masterVectorTrain;
}


void DownloadResults::execute() {
    if (this->masterVectorTest->empty()) {
        string emptyMessage = "please upload data";
        this->dio->write(emptyMessage);
    } else if (this->masterVectorTest->at(0).getStr().empty()) {
        string notClassified = "please classify the data";
        this->dio->write(notClassified);
    } else {
        string vectorSize = to_string(this->masterVectorTest->size());
        this->dio->write(vectorSize);
        int loopSize = (int)this->masterVectorTest->size();
        int i;
        for (i = 0; i < loopSize; i++) {
            string resultDisplay = to_string(i + 1) + "\t" + this->masterVectorTest->at(i).getStr();
            this->dio->write(resultDisplay);
        }
        string done = "Done.";
        this->dio->write(done);
//        this->dio->read();
    }
}
