
#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "CsvReading.h"
#include "Minkowski.h"


void UploadCSV::execute() {
    vector<VectorBase> masterVectorTrain;
    cout << "Please upload your local train CSV file."<<endl;
    string line = this->dio.read();
    while (line!="EOF") {
        istringstream lineStream(line);
        string s;
        vector<double> digitVector;
        while (getline(lineStream, s, ',')) {
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
        line = this->dio.read();
    }

    cout << "Upload complete." << std::endl;

    int vectorSize = masterVectorTrain.at(0).getDigitVectorSize();
    vector<VectorBase> masterVectorTest;
    cout << "Please upload your local test CSV file."<<endl;
    line = this->dio.read();
    while (line!="EOF") {
        istringstream lineStream(line);
        string s;
        vector<double> digitVector;
        for(int i=0; i<vectorSize; i++){
            getline(lineStream, s, ',');
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
        VectorBase rowVector("", digitVector, 0);
        masterVectorTest.push_back(rowVector);
        // Clearing the string stream.
        lineStream.str("");
        // Clearing the vector.
        digitVector.clear();
        line = this->dio.read();
    }

    cout << "Upload complete." << std::endl;

//        // Send fileContent to server
//        // ...
//
//        // Receive server response
//        std::string serverResponse;
//        // ...
//
//        if (serverResponse == ".Upload complete") {
//            std::cout << "Upload complete." << std::endl;
//        } else {
//            std::cout << "Server error: " << serverResponse << std::endl;
//        }
//     else {
//        std::cout << "Invalid input" << std::endl;
//    }
}

