#ifndef EX4_AP_UPLOADCSV_H
#define EX4_AP_UPLOADCSV_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"


class UploadCSV : public Command {
public:
    UploadCSV(DefaultIO *dio);
    void execute() override;
};

#endif //EX4_AP_UPLOADCSV_H
