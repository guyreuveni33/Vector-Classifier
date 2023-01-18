//
// Created by oem on 1/16/23.
//

#ifndef EX4_AP_SETALGO_H
#define EX4_AP_SETALGO_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"


class SetAlgo : public Command {
public:
    void execute() override;
    SetAlgo(DefaultIO *dio);
};

#endif //EX4_AP_SETALGO_H
