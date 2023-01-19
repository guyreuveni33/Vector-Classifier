// Created by oem on 1/17/23.
//
#define COMMAND_H
#ifndef EX4_AP_COMMAND_H
#define EX4_AP_COMMAND_H

#include <string>
#include "DefaultIO.h"
#include <iostream>


using namespace std;

class Command {
public:
    //Command(int value);
    //virtual ~Command();
    virtual void execute() = 0;
protected:
    string description;
    DefaultIO *dio;
};

#endif //EX4_AP_COMMAND_H
