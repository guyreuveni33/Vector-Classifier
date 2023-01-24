#ifndef EX4_AP_SOCKETIO_H
#define EX4_AP_SOCKETIO_H

#include <string>
#include "DefaultIO.h"

using namespace std;

class SocketIO : public DefaultIO {
public:
    SocketIO(int sock) {
        socket = sock;
    }

/**
 * It reads the data from the client and returns it as a string
 *
 * @return The buffer is being returned.
 */
    string read() override;

/**
 * It sends the string to the client and receives a confirmation from the client
 *
 * @param s The string to be sent to the client.
 */
    void write(string s) override;

private:
    int socket;
};

#endif //EX4_AP_SOCKETIO_H
