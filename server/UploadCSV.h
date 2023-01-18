#ifndef EX4_AP_UPLOADCSV_H
#define EX4_AP_UPLOADCSV_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"


class UploadCSV : public Command {
public:
    void execute() override;
    UploadCSV(DefaultIO *dio);
};

#endif //EX4_AP_UPLOADCSV_H
