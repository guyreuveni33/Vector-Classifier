#include "ClassifyData.h"
//
// Created by oem on 1/19/23.
//


ClassifyData::ClassifyData(DefaultIO *dio) {
    this->dio = dio;
    this->description = "classify data";
}
void ClassifyData::execute() {
string feedback=this->dio->read();
cout<<feedback<<endl;
}

