#include "SocketIO.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

using namespace std;

/**
 * It reads the input from the client and returns it as a string
 *
 * @return The buffer.
 */
string SocketIO::read() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    // Receiving the input from the client.
    memset(&buffer, 0, sizeof(buffer));
    int read_bytes = recv(this->socket, buffer, expected_data_len, 0);
    send(this->socket, buffer, 1, 0);
    if (read_bytes == 0) {
        cout << "connection closed";
    } else if (read_bytes < 0) {
        cout << "failed to read data";
    }
    return buffer;
}

/**
 * It sends the string to the client and receives a confirmation from the client
 *
 * @param s The string to send to the client.
 */
void SocketIO::write(string s) {
    char buffer[2];
    // Receiving the input from the client.
    int sent_bytes = send(this->socket, s.c_str(), s.size(), 0);
    recv(this->socket, buffer, 1, 0);
    // It checks if the number of bytes sent to the client is less than 0. If it is, it prints an error message.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}