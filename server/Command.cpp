#include "Command.h"//

class Command {
public:
    Command(int value) : value_(value) {
        // constructor code
    }
    virtual ~Command() {
        // destructor code
    }
    virtual void Execute() = 0;

protected:
    int value_;
};
