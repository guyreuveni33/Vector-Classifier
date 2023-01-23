//
// Created by oem on 1/22/23.
//

#include "CLI.h"
//
// Created by oem on 1/22/23.
//



CLI::CLI(DefaultIO *dio) {
    this->dio = dio;
    Command *uploadCSV = new UploadCSV(dio);
    Command *setAlgo = new SetAlgo(dio);
    Command *classifyData = new ClassifyData(dio);
    Command *displayResults = new DisplayResults(dio);
    Command *downloadResults = new DownloadResults(dio);
    this->commandVector.push_back(uploadCSV);
    this->commandVector.push_back(setAlgo);
    this->commandVector.push_back(classifyData);
    this->commandVector.push_back(displayResults);
    this->commandVector.push_back(downloadResults);
}

void CLI::start() {
    Command *uploadCSV = new UploadCSV(this->dio);
    Command *setAlgo = new SetAlgo(this->dio);
    Command *classifyData = new ClassifyData(this->dio);
    Command *displayResults = new DisplayResults(this->dio);
    Command *downloadResults = new DownloadResults(this->dio);
    int option;
    string menu;
    do {
        menu = this->dio->read();
        cout << menu << endl;
        cin >> option;
        switch (option) {
            case 1:
                this->dio->write(to_string(option));
                uploadCSV->execute();
                break;
            case 2:
                this->dio->write(to_string(option));
                setAlgo->execute();
                break;
            case 3:
                this->dio->write(to_string(option));
                classifyData->execute();
                break;
            case 4:
                this->dio->write(to_string(option));
                displayResults->execute();
                break;
            case 5:
                this->dio->write(to_string(option));
                downloadResults->execute();
                break;
            case 8:
                this->dio->write(to_string(option));
                break;
            default:
                break;
        }
    } while (option != 8);
}