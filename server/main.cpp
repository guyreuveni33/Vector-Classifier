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
    if (argc!=3){
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
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    while(true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            cout << "connection closed";
            close(sock);
            break;
        } else if (read_bytes < 0) {
            cout << "failed to read data";
            close(sock);
            break;
        } else {
            calculate(buffer, fileName);

        }

        int sent_bytes = send(client_sock, buffer, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
            break;
        }
        //calculate(buffer, fileName);
    }
    close(sock);
    return 0;
}
/*
int calculate(char buffer[], string fileName) {

    vector<VectorBase> masterVector;
    vector<double> inputVector;
    int k = stoi();//input the k value from the buffer here
    //string fileName = argv[2];
    string distanceAlgo = ; //input the distance algo from the buffer here
    while (true) {
        insertToVector(inputVector);
        csvIsValid(k, fileName, distanceAlgo, masterVector, inputVector);
        masterVector.clear();
        inputVector.clear();
    }*/

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
                exit(0);
            }
        }
    }
    // Use the extracted values to calculate the distance
    std::vector<VectorBase> masterVector;

    csvIsValid(k, fileName, distanceAlgo, masterVector, inputVector);
    masterVector.clear();
    inputVector.clear();

}

