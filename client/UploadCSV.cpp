#include "UploadCSV.h"
#include <iostream>
#include <map>

UploadCSV::UploadCSV(DefaultIO *dio) {
    this->dio = dio;
}
void UploadCSV::execute() {
    string startMsg = this->dio->read();
    cout << startMsg << endl;
    string fileNameTrain;
    cin>>fileNameTrain;
    string textLine;
    // Opening the file and reading it.
    fstream file(fileNameTrain, ios::in);
    // This is reading the csv file and storing the data into a vector.
    if (file.is_open()) {
        while (getline(file, textLine)) {
            this->dio->write(textLine);
        }
        file.close();
    } else {
        string s = "invalid input";
        cout << s << endl;
        this->dio->write(s);
        return;
    }
    this->dio->write("EOF");
    string uploadComplete = this->dio->read();
    cout << uploadComplete << endl;

    string SecondStartMsg = this->dio->read();
    cout << SecondStartMsg << endl;
    string fileNameTest;
    cin>>fileNameTest;
    // Opening the file and reading it.
    fstream file2(fileNameTest, ios::in);
    // This is reading the csv file and storing the data into a vector.
    //check if file 2 can be open
    if (file2.is_open()) {
        while (getline(file2, textLine)) {
            this->dio->write(textLine);
        }
        file.close();
    } else {
        string s = "invalid input";
        cout << s << endl;
        this->dio->write(s);
        return;
    }
    this->dio->write("EOF");
    uploadComplete = this->dio->read();
    cout << uploadComplete << endl;
}



