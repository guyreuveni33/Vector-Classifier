
#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "CsvReading.h"
#include "Minkowski.h"

UploadCSV::UploadCSV(DefaultIO *dio) {
    this->dio = dio;
    this->description = "";
}
void UploadCSV::execute() {
    vector<VectorBase> masterVectorTrain;
    string trainUpload = "Please upload your local train CSV file.";
    this->dio->write(trainUpload);
    string line = this->dio->read();
    while (line!="EOF") {
        istringstream lineStream(line);
        string s;
        vector<double> digitVector;
        while (getline(lineStream, s, ',')) {
            char br = s.back();
            if(br == '\r')
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
        masterVectorTrain.push_back(rowVector);
        // Clearing the string stream.
        lineStream.str("");
        // Clearing the vector.
        digitVector.clear();
        line = this->dio->read();
    }

    string complete = "Upload complete.";
    this->dio->write(complete);
    int vectorSize = masterVectorTrain.at(0).getDigitVectorSize();
    vector<VectorBase> masterVectorTest;
    string testUpload = "Please upload your local test CSV file.";
    this->dio->write(testUpload);
    line = this->dio->read();

    while (line!="EOF") {
        istringstream lineStream(line);
        string s;
        vector<double> digitVector;
        //for(int i=0; i<vectorSize; i++){
        while(getline(lineStream, s, ',')){
            char br = s.back();
            if(br == '\r')
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
        if(digitVector.size()!=vectorSize)
        {
            string mismatch ="the size of the vectors in both files does not match";
            this->dio->write(mismatch);
            exit(0);
        }
        VectorBase rowVector("", digitVector, 0);
        masterVectorTest.push_back(rowVector);
        // Clearing the string stream.
        lineStream.str("");
        // Clearing the vector.
        digitVector.clear();
        line = this->dio->read();
    }
    this->dio->write(complete);
}

