//
// Created by oem on 1/22/23.
//

#ifndef EX4_AP_CLI_H
#define EX4_AP_CLI_H
//
// Created by oem on 1/22/23.
//
#define EX4_AP_CLI_H
#include "Command.h"
#include "UploadCSV.h"
#include "SetAlgo.h"
#include "ClassifyData.h"
#include "DisplayResults.h"
#include "DownloadResults.h"
#include <vector>
#include "vector"

class CLI {
public:
    //A function that calculates the distance between two vectors.
    CLI(DefaultIO *dio);
    void start();

private:
    DefaultIO *dio;
    vector<Command*> commandVector;
};


#endif //EX4_AP_CLI_H

