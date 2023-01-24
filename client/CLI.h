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
#include <netinet/in.h>
#include <unistd.h>
class CLI {
public:

/**
 * It creates a new CLI object, and initializes the commandVector with the five commands
 *
 * @param dio The DefaultIO object that will be used to communicate with the user.
 */
    CLI(DefaultIO *dio, int socket);

/**
 * It reads the menu from the server, prints it to the user, reads the user's choice, sends it to the server, and executes
 * the appropriate command
 */
    void start();

private:
    int socket;
    DefaultIO *dio;
    vector<Command *> commandVector;
};


#endif //EX4_AP_CLI_H

