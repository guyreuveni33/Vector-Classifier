#ifndef EX4_AP_UPLOADCSV_H
#define EX4_AP_UPLOADCSV_H

#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"


class UploadCSV : public Command {
public:
/**
 * The constructor for the UploadCSV class takes a pointer to a DefaultIO object as an argument and assigns it to the dio
 * member variable.
 *
 * @param dio The DefaultIO object that will be used to read the CSV file.
 */
    UploadCSV(DefaultIO *dio);

/**
 * This function reads the csv file and sends it to the server
 *
 */
    void execute() override;
};

#endif //EX4_AP_UPLOADCSV_H
