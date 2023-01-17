//
// Created by oem on 1/16/23.
//

#ifndef EX4_AP_UPLOADCSV_H
#define EX4_AP_UPLOADCSV_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"


class UploadCSV : public Command {
private:
    std::string filePath;
    std::string fileContent;

public:
    void execute() override;
};

#endif //EX4_AP_UPLOADCSV_H
