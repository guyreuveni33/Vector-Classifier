#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc!=3){
        exit(0);
    }
    const char *ip_address = argv[1];
    int port_no;
    try {
        port_no = atoi(argv[2]);
    }
    catch (exception &e) {
        exit(0);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    while(true) {
        string userInput;
        getline(cin, userInput);
        if (userInput == "-1") {
            break;
        }
        char arrayUserInput[userInput.size() + 1];
        strncpy(arrayUserInput, userInput.c_str(), userInput.size());
        arrayUserInput[userInput.size()] = '\0';
        int data_len = strlen(arrayUserInput);
        int sent_bytes = send(sock, arrayUserInput, data_len, 0);
        if (sent_bytes < 0) {
            cout << "failed to send data";
            break;
        }
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            cout << "connection closed";
            break;
        } else if (read_bytes < 0) {
            cout << "failed to receive data";
            break;
        } else {
            cout << buffer;
        }
    }
    close(sock);
    return 0;
}

