#include "CLI.h"


CLI::CLI(DefaultIO *dio) {
    vector<VectorBase> *v1 = new vector<VectorBase>();
    vector<VectorBase> *v2 = new vector<VectorBase>();

    this->dio = dio;
    Command *uploadCSV = new UploadCSV(dio, v1, v2);
    Command *setAlgo = new SetAlgo(dio, v1, v2);
    Command *classifyData = new ClassifyData(dio, v1, v2, (SetAlgo *) setAlgo);
    Command *displayResults = new DisplayResults(dio, v1, v2);
    Command *downloadResults = new DownloadResults(dio, v1, v2);
    this->commandVector.push_back(uploadCSV);
    this->commandVector.push_back(setAlgo);
    this->commandVector.push_back(classifyData);
    this->commandVector.push_back(displayResults);
    this->commandVector.push_back(downloadResults);
}


void CLI::start() {
    int i;
    do {
        string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n"
                      "1. upload an unclassified csv data file\n"
                      "2. algorithm settings\n"
                      "3. classify data\n"
                      "4. display results\n"
                      "5. download results\n"
                      "8. exit";
        this->dio->write(menu);
        string choice = this->dio->read();
        if (choice == "invalid choice") {
            continue;
        }
        try {
            i = stoi(choice);
            if(i == 8){
                break;
            }
        }
        catch (exception &e) {
            return;
        }
        this->commandVector.at(i - 1)->execute();
    } while (i != 8);
    for (int j = 0; j < commandVector.size(); ++j) {
        free(commandVector.at(j));
    }
    free(dio);
}