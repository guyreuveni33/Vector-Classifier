//
// Created by niv swisa on 17/01/2023.
//

#ifndef EX4_AP_SOCKETIO_H
#define EX4_AP_SOCKETIO_H

#include <string>;
#include "DefaultIO.h";

using namespace std;

class SocketIO : public DefaultIO{
public:
    SocketIO(int sock) {
        socket = sock;
    }
    string read() override;
    void write(string s) override;
private:
    int socket;
};
#endif //EX4_AP_SOCKETIO_H
