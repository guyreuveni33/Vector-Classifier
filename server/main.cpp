#include "MasterDistance.h"
#include "VectorCreation.h"
#include "VectorBase.h"
#include "CsvReading.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <sstream>

using namespace std;


string calculate(char buffer[], string fileName);


int main(int argc, char *argv[]) {
    if (argc != 3) {
        exit(0);
    }
    string fileName = argv[1];
    int server_port;
    try {
        server_port = atoi(argv[2]);
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
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (::bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 1) < 0) {
        perror("error listening to a socket");
    }
    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        while (true) {
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            string c;
            if (read_bytes == 0) {
                cout << "connection closed";
                break;
            } else if (read_bytes < 0) {
                cout << "failed to read data";
                break;
            } else {
                c = calculate(buffer, fileName);
                if (c == "-1") {
                    break;
                }
                memset(&buffer, 0, sizeof(buffer));
                strncpy(buffer, c.c_str(), c.size());
                buffer[c.size()] = '\0';
            }
            read_bytes = c.length();
            int sent_bytes = send(client_sock, buffer, read_bytes, 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
                break;
            }
        }
        close(client_sock);
    }
    close(sock);
    return 0;
}


string calculate(char buffer[], std::string fileName) {
    // Initialize the stringstream with the buffer string
    std::stringstream ss(buffer);
    // Extract all the numbers until the first letter and save them in inputVector
    std::vector<double> inputVector;
    string s, distanceAlgo;
    int k;
    while (ss >> s) {
        try {
            inputVector.push_back(stod(s));
        } catch (exception &e) {
            distanceAlgo = s;
            ss >> s;
            try {
                k = stoi(s);
            } catch (exception &e) {
                string retStr = "invalid input";
                return retStr;
            }
        }
    }
    // Use the extracted values to calculate the distance
    std::vector<VectorBase> masterVector;

    string finalClass = csvIsValid(k, fileName, distanceAlgo, masterVector, inputVector);
    masterVector.clear();
    inputVector.clear();
    return finalClass;
}

