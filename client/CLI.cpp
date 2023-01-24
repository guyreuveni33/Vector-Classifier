#include "CLI.h"

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
    //Command *uploadCSV = new UploadCSV(this->dio);
    //Command *setAlgo = new SetAlgo(this->dio);
    //Command *classifyData = new ClassifyData(this->dio);
    //Command *displayResults = new DisplayResults(this->dio);
    //Command *downloadResults = new DownloadResults(this->dio);
    string option;
    int userChoice;
    string menu;
    do {
        option.clear();
        menu = this->dio->read();
        cout << menu << endl;
        getline(cin, option);
        try {
            if(option.empty())
                throw exception();
            userChoice = stoi(option);
        } catch (exception &e) {
            cout << "invalid input" << endl;
            string invalidChoice = "invalid choice";
            this->dio->write(invalidChoice);
            continue;
        }
        switch (userChoice) {
            case 1:
                this->dio->write(to_string(userChoice));
                commandVector.at(0)->execute();
                break;
            case 2:
                this->dio->write(to_string(userChoice));
                commandVector.at(1)->execute();
                break;
            case 3:
                this->dio->write(to_string(userChoice));
                commandVector.at(2)->execute();
                break;
            case 4:
                this->dio->write(to_string(userChoice));
                commandVector.at(3)->execute();
                break;
            case 5:
                this->dio->write(to_string(userChoice));
                commandVector.at(4)->execute();
                break;
            case 8:
                cout << "Goodbye!" << endl;
                this->dio->write(to_string(userChoice));
                break;
            default:
                cout << "invalid input" << endl;
                string invalidChoice = "invalid choice";
                this->dio->write(invalidChoice);
                break;
        }
    } while (userChoice != 8);
}
