#include "ClassifyData.h"
//
// Created by oem on 1/19/23.
//

//#/Users/nivswisa/CLionProjects/ex4_AP/client/cmake-build-debug/datasets/beans/beans_Classified.csv
//#/Users/nivswisa/CLionProjects/ex4_AP/client/cmake-build-debug/datasets/beans/beans_UnClassified.csv
ClassifyData::ClassifyData(DefaultIO *dio) {
    this->dio = dio;
    this->description = "classify data";
}
void ClassifyData::execute() {
string feedback=this->dio->read();
cout<<feedback<<endl;
}

