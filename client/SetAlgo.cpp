//
// Created by oem on 1/16/23.
//

#include "SetAlgo.h"
#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>

SetAlgo::SetAlgo(DefaultIO *dio) {
    this->dio = dio;
    this->description = "algorithm settings";
}
void SetAlgo::execute() {
    string currentKNN;
    currentKNN=this->dio->read();
    cout<<currentKNN<<endl;
    string newParameters;
    getline(cin,newParameters);
    if (newParameters.empty()){
        string emptyInput="-1";
        this->dio->write(emptyInput);
    }
    else {
        this->dio->write(newParameters);
    }
    if (!newParameters.empty()){
        string errorCheck = this->dio->read();
    if (errorCheck=="1")
    cout << "invalid value for K" << endl;
    else if (errorCheck=="2")
    cout << "invalid value for metric" << endl;
    else if(errorCheck=="3"){
    cout << "invalid value for K" << endl;
    cout << "invalid value for metric" << endl;
}
    }
}

