//
// Created by oem on 1/22/23.
//

#ifndef EX4_AP_DOWNLOADRESULTS_H
#define EX4_AP_DOWNLOADRESULTS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"

class DownloadResults : public Command {
public:
    void execute() override;

    DownloadResults(DefaultIO *dio);

};

#endif //EX4_AP_DOWNLOADRESULTS_H
