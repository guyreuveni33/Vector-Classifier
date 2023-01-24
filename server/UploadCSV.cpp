#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>


UploadCSV::UploadCSV(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest) {
    this->dio = dio;
    this->description = "upload an unclassified csv data file";
    this->masterVectorTrain = masterVectorTrain;
    this->masterVectorTest = masterVectorTest;
}


void UploadCSV::execute() {
    string trainUpload = "Please upload your local train CSV file.";
    this->dio->write(trainUpload);
    string line = this->dio->read();
    if (line == "invalid input") {
        return;
    }
    // This is checking if the vectors are empty. If they are not, it will clear them.
    if (!masterVectorTrain->empty() || !masterVectorTest->empty()) {
        masterVectorTrain->clear();
        masterVectorTest->clear();
    }
    // This is reading in the CSV file and storing the data in a vector of VectorBase objects.
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
                    return;
                }
            }
        }
        VectorBase rowVector(s, digitVector, 0);
        this->masterVectorTrain->push_back(rowVector);
        // Clearing the string stream.
        lineStream.str("");
        // Clearing the vector.
        digitVector.clear();
        line = this->dio->read();
    }
    string complete = "Upload complete.";
    this->dio->write(complete);
    int vectorSize = this->masterVectorTrain->at(0).getDigitVectorSize();
    string testUpload = "Please upload your local test CSV file.";
    this->dio->write(testUpload);
    line = this->dio->read();
    if (line == "invalid input") {
        return;
    }
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
                    return;
                }
            }
        }
        if (digitVector.size() != vectorSize) {
            string mismatch = "the size of the vectors in both files does not match";
            this->dio->write(mismatch);
            exit(0);
        }
        VectorBase rowVector("", digitVector, 0);
        this->masterVectorTest->push_back(rowVector);
        // Clearing the string stream.
        lineStream.str("");
        // Clearing the vector.
        digitVector.clear();
        line = this->dio->read();
    }
    this->dio->write(complete);
}
