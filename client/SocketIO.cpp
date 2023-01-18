#include "SocketIO.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <sstream>

using namespace std;

string SocketIO::read(){
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    // Receiving the input from the client.
    memset(&buffer, 0, sizeof(buffer));
    int read_bytes = recv(this->socket, buffer, expected_data_len, 0);
    send(this->socket, buffer,1, 0);
    if (read_bytes == 0) {
        cout << "connection closed";
    } else if (read_bytes < 0) {
        cout << "failed to read data";
    }
    return buffer;
}

void SocketIO::write(string s){
    char buffer[2];
    // Receiving the input from the client.
    int sent_bytes = send(this->socket, s.c_str(), s.size(), 0);
    recv(this->socket, buffer, 1, 0);
    // It checks if the number of bytes sent to the client is less than 0. If it is, it prints an error message.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}