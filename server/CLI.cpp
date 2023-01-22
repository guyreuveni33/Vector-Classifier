//
// Created by oem on 1/22/23.
//

#include "CLI.h"


CLI::CLI(DefaultIO *dio) {
    vector<VectorBase> v1;
    vector<VectorBase> v2;

    vector<VectorBase> *v1Ptr = &v1;
    vector<VectorBase> *v2Ptr = &v2;
    this->dio = dio;
    Command *uploadCSV = new UploadCSV(dio, v1Ptr,v2Ptr);
    Command *setAlgo = new SetAlgo(dio, v1Ptr, v2Ptr);
    Command *classifyData = new ClassifyData(dio, v1Ptr, v2Ptr, ((SetAlgo*)(setAlgo))->getK(),
                                             ((SetAlgo*)(setAlgo))->getDistanceMetric());
    Command *displayResults = new DisplayResults(dio, v1Ptr, v2Ptr);
    Command *downloadResults = new DownloadResults(dio, v1Ptr, v2Ptr);
    this->commandVector.push_back(uploadCSV);
    this->commandVector.push_back(setAlgo);
    this->commandVector.push_back(classifyData);
    this->commandVector.push_back(displayResults);
    this->commandVector.push_back(downloadResults);
}


void CLI:: start(){
    int i;
    do {
        string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n"
                      "1. upload an unclassified csv data file\n"
                      "2. algorithm settings\n"
                      "3. classify data\n"
                      "4. display results\n"
                      "5. download results\n"
                      "8. exit";
        this->dio->write(menu);
        string choice = this->dio->read();
        try {
            i = stoi(choice);
        }
        catch (exception &e) {
            return;
        }
        this->commandVector.at(i-1)->execute();
    }while (i!=8);
    }