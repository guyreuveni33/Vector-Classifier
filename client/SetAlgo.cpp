#include "SetAlgo.h"
#include <iostream>
#include <string>
#include <map>

SetAlgo::SetAlgo(DefaultIO *dio) {
    this->dio = dio;
    this->description = "algorithm settings";
}
void SetAlgo::execute() {
    string currentKNN;
    currentKNN=this->dio->read();
    cout<<currentKNN<<endl;
    string newParameters;
    cin.ignore();
    getline(cin,newParameters);
    //cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    if (newParameters.empty()){
        string emptyInput="-1";
        this->dio->write(emptyInput);
    }
    else {
        this->dio->write(newParameters);
    }
    if (!newParameters.empty()){
        string errorCheck = this->dio->read();
        int intErrorCheck= stoi(errorCheck);
        if (intErrorCheck==1)
            cout << "invalid value for K" << endl;
        else if (intErrorCheck==2)
            cout << "invalid value for metric" << endl;
        else if(intErrorCheck==3){
            cout << "invalid value for K" << endl;
            cout << "invalid value for metric" << endl;
}       else if(intErrorCheck>=10){
            cout << "too many arguments" << endl;
    }
}}

