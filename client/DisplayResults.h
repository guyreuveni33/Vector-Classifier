#ifndef EX4_AP_DISPLAYRESULTS_H
#define EX4_AP_DISPLAYRESULTS_H

#include "Command.h"


class DisplayResults : public Command {
public:

/**
 * It reads the feedback from the server, and if the feedback is "please upload data" or "please classify the data", it
 * prints the feedback. Otherwise, it reads the number of results from the server, and then reads the results from the
 * server and prints them. Finally, it reads "done" from the server and prints it
 */
    void execute() override;

/**
 * The constructor for the DisplayResults class takes a pointer to a DefaultIO object as an argument and assigns it to the
 * dio member variable.
 *
 * @param dio The DefaultIO object that will be used to display the results.
 */
    DisplayResults(DefaultIO *dio);
};
#endif //EX4_AP_DISPLAYRESULTS_H
