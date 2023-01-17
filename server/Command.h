// Created by oem on 1/17/23.
//
#define COMMAND_H

class Command {
public:
    Command(int value);
    virtual ~Command();
    virtual void Execute() = 0;

protected:
    int value_;
};

#ifndef EX4_AP_COMMAND_H
#define EX4_AP_COMMAND_H

#endif //EX4_AP_COMMAND_H
