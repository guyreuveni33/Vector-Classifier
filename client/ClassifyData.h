#ifndef EX4_AP_CLASSIFYDATA_H
#define EX4_AP_CLASSIFYDATA_H


#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"

class ClassifyData : public Command {
public:
    void execute() override;
    ClassifyData(DefaultIO *dio);


};

#endif //EX4_AP_CLASSIFYDATA_H
