//
// Created by niv swisa on 17/01/2023.
//

#ifndef EX4_AP_DEFAULTIO_H
#define EX4_AP_DEFAULTIO_H

#include <string>
using namespace std;
//#/home/oem/CLionProjects/ex4_AP/server/datasets/iris/iris_Unclassified1.csv
//#/home/oem/CLionProjects/ex4_AP/server/datasets/iris/iris_Unclassified.csv
//#/home/oem/CLionProjects/ex4_AP/server/datasets/iris/iris_classified.csv
class DefaultIO {
public:
    virtual string read() = 0;
    virtual void write(string s) = 0;
protected:
    string description;

};
#endif //EX4_AP_DEFAULTIO_H
