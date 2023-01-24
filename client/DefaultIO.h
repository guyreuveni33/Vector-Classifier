#ifndef EX4_AP_DEFAULTIO_H
#define EX4_AP_DEFAULTIO_H

#include <string>
using namespace std;

class DefaultIO {
public:
    //virtual method
    virtual string read() = 0;
    //virtual method
    virtual void write(string s) = 0;
protected:
    string description;

};
#endif //EX4_AP_DEFAULTIO_H