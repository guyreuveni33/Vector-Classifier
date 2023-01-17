//
// Created by niv swisa on 17/01/2023.
//

#ifndef EX4_AP_DEFAULTIO_H
#define EX4_AP_DEFAULTIO_H

#include <string>;

using namespace std;

class DefaultIO {
public:
    virtual string read();
    virtual void write(string s);
protected:
    string description;

};
#endif //EX4_AP_DEFAULTIO_H
