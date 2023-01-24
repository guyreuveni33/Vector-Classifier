#ifndef EX4_AP_CLI_H
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
/**
 * It creates a vector of commands, and then pushes the commands into the vector
 *
 * @param dio DefaultIO object
 */
    CLI(DefaultIO *dio);

/**
 * It displays a menu, reads the user's choice, and executes the corresponding command
 */
    void start();


private:
    DefaultIO *dio;
    vector<Command *> commandVector;
};


#endif //EX4_AP_CLI_H
