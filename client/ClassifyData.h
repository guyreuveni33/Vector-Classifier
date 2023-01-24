#ifndef EX4_AP_CLASSIFYDATA_H
#define EX4_AP_CLASSIFYDATA_H


#include <iostream>
#include <fstream>
#include <string>
#include "Command.h"

class ClassifyData : public Command {
public:

/**
 * It reads the data from the input stream and prints it to the console
 */
    void execute() override;

    /**
 * It takes a pointer to a DefaultIO object and assigns it to the dio member variable
 *
 * @param dio This is the DefaultIO object that will be used to read and write data.
 */
    ClassifyData(DefaultIO *dio);


};

#endif //EX4_AP_CLASSIFYDATA_H
