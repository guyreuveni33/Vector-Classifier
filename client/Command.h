#ifndef EX4_AP_COMMAND_H
#define EX4_AP_COMMAND_H

#include <string>
#include "DefaultIO.h"
#include <iostream>


using namespace std;

class Command {
public:
    //virtual method
    virtual void execute() = 0;
protected:
    string description;
    DefaultIO *dio;
};

#endif //EX4_AP_COMMAND_H
