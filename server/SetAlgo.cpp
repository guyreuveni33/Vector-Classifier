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

SetAlgo::SetAlgo(DefaultIO *dio) {
    this->dio = dio;
    this->description = "algorithm settings";
    this->k=5;
    this->distanceMetric="AUC";
}
void SetAlgo::execute() {
    string currentParameters="The current KNN parameters are: K = "+ to_string(this->k)+
        ", distance metric = "+ this->distanceMetric;
    string newDistanceMetric;
    string newK;

    int counter=0;
    string kError;
    this->dio->write(currentParameters);
    string input=this->dio->read();
    if (input!="-1"){
        istringstream lineStream(input);
         getline(lineStream, newK, ' ');
         try {
             stoi(newK);
         }
         catch(exception &e) {
             counter++;
         }
         getline(lineStream, newDistanceMetric, ' ');
            if (newDistanceMetric != "AUC" && newDistanceMetric != "MAN" && newDistanceMetric != "CHB" && newDistanceMetric != "CAN"
                && newDistanceMetric != "MIN") {
                counter+=2;
        }
        string validLine;
        getline(lineStream, validLine, ' ');
        if(!validLine.empty())
            counter+=10;
        string errorClassification= to_string(counter);
            this->dio->write(errorClassification);
        if (counter==0){
            this->k=stoi(newK);
            this->distanceMetric=newDistanceMetric;
        }
    }

}

