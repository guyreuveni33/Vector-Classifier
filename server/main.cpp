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
int calculate(char buffer[]);

/**
 * This function is the main function of the program. It takes in the command line arguments and calls the other
 * functions to run the program
 *
 * @param argc the number of arguments passed to the program
 * @param argv
 */
int main() {
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket"); }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (::bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket"); }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        perror("error accepting client"); }
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
// connection is closed
    }
    else if (read_bytes < 0) {
// error
    }
    else {
        std::cout << "Server " << buffer; }

    int sent_bytes = send(client_sock, buffer, read_bytes, 0);
    if (sent_bytes < 0) {
        perror("error sending to client"); }
    close(sock);
    calculate(buffer);
    return 0;
}

int calculate(char buffer[]) {

    vector<VectorBase> masterVector;
    vector<double> inputVector;
    int k = stoi(argv[1]);
    string fileName = argv[2];
    string distanceAlgo = argv[3];
    if (argc!=4){
        exit(0);
    }
    while(true) {
        insertToVector(inputVector);
        csvIsValid(k, fileName, distanceAlgo, masterVector, inputVector);
        masterVector.clear();
        inputVector.clear();
    }
}