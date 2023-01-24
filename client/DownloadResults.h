#ifndef EX4_AP_DOWNLOADRESULTS_H
#define EX4_AP_DOWNLOADRESULTS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"
#include <vector>

//A struct that contains a vector of strings and a string.
struct fileStruct {
    vector<string> downloadVector;
    string filePath;
};

/**
 * This function takes a fileStruct as an argument and writes the contents of the downloadVector to the filePath
 *
 * @param f
 *
 */
void foo(fileStruct f);

class DownloadResults : public Command {
public:

/**
 * This function reads the feedback from the server, and if the feedback is "please upload data" or "please classify the
 * data", it prints the feedback. Otherwise, it reads the number of lines of data that the server is sending, and then it
 * reads the data line by line and writes it to a file
 */
    void execute() override;

/**
 * The constructor for the DownloadResults class takes a pointer to a DefaultIO object as an argument and assigns it to the
 * dio member variable.
 *
 * @param dio The DefaultIO object that will be used to write the results to the file.
 */
    DownloadResults(DefaultIO *dio);

};

#endif //EX4_AP_DOWNLOADRESULTS_H
