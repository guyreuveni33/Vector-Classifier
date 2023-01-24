#include "DownloadResults.h"
#include <thread>

DownloadResults::DownloadResults(DefaultIO *dio) {
    this->dio = dio;
}


void DownloadResults::execute() {
    //vector<thread> threads;
    string feedback = this->dio->read();
    if (feedback == "please upload data" || feedback == "please classify the data") {
        cout << feedback << endl;
    } else{
        int loopSize = stoi(feedback);
        int i;
        string theResults;
        // cout << "Please enter the file path where you want to write the results (include .csv extension):" << endl;
        string filePath;
        cin.ignore();
        getline(cin, filePath);
        ofstream outputFile(filePath);
        string success;
        if (outputFile.is_open()) {
            success = "success";
            vector<string> downloadVector;
            fileStruct f;
            for (i = 0; i < loopSize; i++) {
                theResults = this->dio->read();
                downloadVector.push_back(theResults);
                //outputFile << theResults << endl;
            }
            f.downloadVector = downloadVector;
            f.filePath = filePath;
            outputFile.close();
            thread t(foo, f);
            t.detach();
        } else {
            success = "no success";
            cout << "invalid input" << endl;
        }
        this->dio->write(success);
    }
}
void foo(fileStruct f) {
    int i;
    string theResults;
    ofstream outputFile(f.filePath);
    string success;
    if (outputFile.is_open()) {
        //success = "success";
        for (i = 0; i < f.downloadVector.size(); i++) {
            theResults = f.downloadVector.at(i);
            outputFile << theResults << endl;
        }
        outputFile.close();
    } else {
        return;
    }
}


