//
// Created by oem on 1/22/23.
//

#include "DownloadResults.h"


DownloadResults::DownloadResults(DefaultIO *dio) {
    this->dio = dio;
}


void DownloadResults::execute() {
    string feedback = this->dio->read();
    if (feedback == "please upload data" || feedback == "please classify the data") {
        cout << feedback << endl;
    } else {
        int loopSize = stoi(feedback);
        int i;
        string theResults;
        cout << "Please enter the file path where you want to write the results (include .csv extension):" << endl;
        string filePath;
        cin >> filePath;
        ofstream outputFile(filePath);
        for (i = 0; i < loopSize; i++) {
            theResults = this->dio->read();
            outputFile << theResults << endl;
        }
        string done = this->dio->read();
        cout << done << endl;
        outputFile.close();
        string newParameters;
        cin>>newParameters;
        if (newParameters.empty()){
            string emptyInput="-1";
            this->dio->write(emptyInput);
        }
    }
}

