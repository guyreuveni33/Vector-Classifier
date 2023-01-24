#ifndef EX4_AP_COMMAND_H
#define EX4_AP_COMMAND_H

#include <string>
#include "DefaultIO.h"
#include "VectorBase.h"
#include "Minkowski.h"
#include "CsvReading.h"
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

class Command {
public:
    //virtual ~Command();
    virtual void execute() = 0;


protected:
    string description;
    DefaultIO *dio;
};

#endif //EX4_AP_COMMAND_H
