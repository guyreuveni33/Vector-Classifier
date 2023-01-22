#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>


UploadCSV::UploadCSV(DefaultIO *dio, vector<VectorBase> *masterVectorTest, vector<VectorBase> *masterVectorTrain) {
    this->dio = dio;
    this->description = "upload an unclassified csv data file";
    this->masterVectorTrain = vector<VectorBase>();
    this->masterVectorTest = vector<VectorBase>();
}


vector<VectorBase>* UploadCSV::getMasterVectorTrain() {
    return &this->masterVectorTrain;
}


vector<VectorBase>* UploadCSV::getMasterVectorTest() {
    return &this->masterVectorTest;
}

void UploadCSV::execute() {
    //vector<VectorBase> masterVectorTrain;
    string trainUpload = "Please upload your local train CSV file.";
    this->dio->write(trainUpload);
    string line = this->dio->read();
    while (line != "EOF") {
        istringstream lineStream(line);
        string s;
        vector<double> digitVector;
        while (getline(lineStream, s, ',')) {
            char br = s.back();
            if (br == '\r')
                s.erase(s.end() - 1);
            // This is checking if the string is a number. If it is, it will convert it to a double and push it into
            //the vector.
            if (numCheck(s)) {
                try {
                    double d = stod(s);
                    digitVector.push_back(d);
                }
                catch (exception &e) {
                    cout << "invalid input" << endl;
                    break;
                }
            }
        }
        VectorBase rowVector(s, digitVector, 0);
        this->masterVectorTrain.push_back(rowVector);
        // Clearing the string stream.
        lineStream.str("");
        // Clearing the vector.
        digitVector.clear();
        line = this->dio->read();
    }

    string complete = "Upload complete.";
    this->dio->write(complete);
    int vectorSize = this->masterVectorTrain.at(0).getDigitVectorSize();
    string testUpload = "Please upload your local test CSV file.";
    this->dio->write(testUpload);
    line = this->dio->read();

    while (line != "EOF") {
        istringstream lineStream(line);
        string s;
        vector<double> digitVector;
        //for(int i=0; i<vectorSize; i++){
        while (getline(lineStream, s, ',')) {
            char br = s.back();
            if (br == '\r')
                s.erase(s.end() - 1);
            // This is checking if the string is a number. If it is, it will convert it to a double and push it into
            //the vector.
            if (numCheck(s)) {
                try {
                    double d = stod(s);
                    digitVector.push_back(d);
                }
                catch (exception &e) {
                    cout << "invalid input" << endl;
                    break;
                }
            }
        }
        if (digitVector.size() != vectorSize) {
            string mismatch = "the size of the vectors in both files does not match";
            this->dio->write(mismatch);
            exit(0);
        }
        VectorBase rowVector("", digitVector, 0);
        this->masterVectorTest.push_back(rowVector);
        // Clearing the string stream.
        lineStream.str("");
        // Clearing the vector.
        digitVector.clear();
        line = this->dio->read();
    }
    this->dio->write(complete);
}
