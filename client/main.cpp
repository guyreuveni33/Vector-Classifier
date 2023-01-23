#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sstream>
#include "VectorCreation.h"
#include "DefaultIO.h"
#include "SocketIO.h"
#include "Command.h"
#include "UploadCSV.h"
#include "SetAlgo.h"
#include "ClassifyData.h"
#include "DisplayResults.h"
#include "DownloadResults.h"
#include "CLI.h"

using namespace std;

string clientValidation(std::string userInput);

bool is_valid_ipv4(const std::string &ip);

/**
 * This function creates a socket and receives the ip and the port number from the arguments.
 * It then talk to the server that is waiting in the port number.
 * The function sends the server a user input in the format of a string so the server can make the calculations
 * according to the different inputs of the user. This function runs endlessly and asks for a new user input every time,
 * unless the user enters ‘-1’ and then the program shuts down
 *
 * @param argc the number of arguments passed to the program
 * @param argv the arguments passed to the program.
 *
 * @return the result of the calculation.
 */
int main(int argc, char *argv[]) {
    const char *ip_address = argv[1];
    // This is checking if the ip address is valid.
    if (!is_valid_ipv4(ip_address))
        exit(0);
    int port_no;
    try {
        port_no = stoi(argv[2]);
    }
    catch (exception &e) {
        exit(0);
    }
    // This is checking if the port number is valid.
    if (port_no < 1025 || port_no > 65536) {
        exit(0);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // This is checking if the socket was created successfully.
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    // Setting the memory of the struct to 0.
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    // This is the main loop of the client. It gets the user input, validates it, sends it to the server, and then
    // receives the result from the server.
    DefaultIO *dio = new SocketIO(sock);
    CLI *cli = new CLI(dio);
    cli->start();


    close(sock);
    return 0;
}

/**
 * This function runs the tests on the user input and validates it’s values
 *
 * @param userInput The string that the user entered.
 *
 * @return a string.
 */
string clientValidation(std::string userInput) {
    // Initialize the stringstream with the buffer string
    std::stringstream ss(userInput);
    // Extract all the numbers until the first letter and save them in inputVector
    std::vector<double> inputVector;
    string s, distanceAlgo;
    string retStr = " ";
    int k;
    // This is checking if the user input is empty. If it is empty, the program will print "invalid input" and will
    // continue to the next iteration of the loop.
    if (userInput.empty()) {
        retStr = "invalid input";
        return retStr;
    }
    // This is the validation of the user input. It checks if the user input is valid and if it is not valid, it
    // returns "invalid input".
    while (ss >> s) {
        // This is checking if the string is a number. If it is a number, it will push it to the vector.
        if (numCheck(s) == 1) {
            inputVector.push_back(stod(s));
        }
        //This is checking if the user input is empty. If it is empty, the program will print "invalid input" and will
        // continue to the next iteration of the loop.
        if (inputVector.empty()) {
            retStr = "invalid input";
            return retStr;
        }
        if (!numCheck(s)) {
            distanceAlgo = s;
            // This is checking if the distance algorithm is valid. If it is not valid, the program will print invalid
            // input and will continue to the next iteration of the loop.
            if (distanceAlgo != "AUC" && distanceAlgo != "MAN" && distanceAlgo != "CHB" && distanceAlgo != "CAN"
                && distanceAlgo != "MIN") {
                retStr = "invalid input";
                break;
            }
            ss >> s;
            try {
                k = stoi(s);
            } catch (exception &e) {
                retStr = "invalid input";
            }
            break;
        }
    }

    return retStr;
}

/**
 * If the string contains 4 segments, and each segment is a valid integer between 0 and 255, then it's a valid IPv4
 * address
 *
 * @param ip the IP address to validate
 *
 * @return The function is_valid_ipv4() returns true if the string passed to it is a valid IPv4 address, and false
 * otherwise.
 */
bool is_valid_ipv4(const std::string &ip) {
    std::stringstream ip_stream(ip);
    std::string segment;
    int seg_count = 0;
    // This is checking if the ip address is valid.
    while (std::getline(ip_stream, segment, '.')) {
        ++seg_count;
        // This is checking if the ip address has more than 4 segments of numbers.
        if (seg_count > 4) {
            return false;
        }
        int num = 0;
        for (char c: segment) {
            if (!isdigit(c)) {
                return false;
            }
            num = num * 10 + c - '0';
        }
        // This is checking if the number is between 0 and 255.
        if (num < 0 || num > 255) {
            return false;
        }
    }
    return seg_count == 4;
}