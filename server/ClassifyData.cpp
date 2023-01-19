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

ClassifyData::ClassifyData(DefaultIO *dio,vector<VectorBase> &masterVectorTest,vector<VectorBase> &masterVectorTrain) {
    this->dio = dio;
    this->description = "upload an unclassified csv data file";
    this->masterVectorTrain= masterVectorTrain;
    this->masterVectorTest= masterVectorTest;

}

vector<VectorBase>ClassifyData:: getMasterVectorTrain(){
    return this->masterVectorTrain;
}
vector<VectorBase>ClassifyData:: getMasterVectorTest(){
    return this->masterVectorTest;
}
void ClassifyData::execute() {
    if(this->masterVectorTrain.empty()||this->masterVectorTest.empty())
    {
        string emptyMessage="please upload data";
        this->dio->write(emptyMessage);
    }
    
}
