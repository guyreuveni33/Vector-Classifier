#ifndef EX4_AP_DOWNLOADRESULTS_H
#define EX4_AP_DOWNLOADRESULTS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"
#include <vector>

struct fileStruct{
    vector<string> downloadVector;
    string filePath;
};
void foo(fileStruct f);

class DownloadResults : public Command {
public:

    void execute() override;

    DownloadResults(DefaultIO *dio);

};

#endif //EX4_AP_DOWNLOADRESULTS_H
