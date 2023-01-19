//
// Created by niv swisa on 19/01/2023.
//

#ifndef EX4_AP_DISPLAYRESULTS_H
#define EX4_AP_DISPLAYRESULTS_H

#include "Command.h"


class DisplayResults : public Command {
public:
    void execute() override;

    DisplayResults(DefaultIO *dio);
};
#endif //EX4_AP_DISPLAYRESULTS_H
