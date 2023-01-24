#ifndef EX4_AP_SETALGO_H
#define EX4_AP_SETALGO_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"


class SetAlgo : public Command {
public:

/**
 * It reads the current KNN parameters from the server, then reads the new parameters from the user, and sends them to the
 * server
 */

    void execute() override;

/**
 * It creates a new SetAlgo object, which is a subclass of the Set class
 *
 * @param dio This is the DefaultIO object that is used to communicate with the user.
 */
    SetAlgo(DefaultIO *dio);
};

#endif //EX4_AP_SETALGO_H
