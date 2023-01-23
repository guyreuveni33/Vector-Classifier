//
// Created by niv swisa on 19/01/2023.
//

#include "DisplayResults.h"


DisplayResults::DisplayResults(DefaultIO *dio) {
    this->dio = dio;
}


void DisplayResults::execute() {
    string feedback = this->dio->read();
    if (feedback == "please upload data" || feedback == "please classify the data") {
        cout << feedback << endl;
    } else {
        int loopSize = stoi(feedback);
        int i;
        string theResults;
        for (i = 0; i < loopSize; i++) {
            theResults = this->dio->read();
            cout << theResults << endl;
        }
        string done = this->dio->read();
        cout << done << endl;
        string newParameters;
        cin.ignore();
        getline(cin,newParameters);
        if (newParameters.empty()){
            string emptyInput="-1";
            this->dio->write(emptyInput);
        }
        // Do something with the input

//        }
        //char a;
        // int counter;
        //cout<<"Type:"<<endl;
    }
}
