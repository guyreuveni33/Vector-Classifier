#include "MasterDistance.h"
#include "VectorCreation.h"
#include "VectorBase.h"
#include "CsvReading.h"

using namespace std;

/**
 * This function is the main function of the program. It takes in the command line arguments and calls the other
 * functions to run the program
 *
 * @param argc the number of arguments passed to the program
 * @param argv
 */
int main(int argc, char *argv[]) {
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