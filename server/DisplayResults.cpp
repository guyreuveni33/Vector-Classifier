#include "DisplayResults.h"




DisplayResults::DisplayResults(DefaultIO *dio, vector<VectorBase> *masterVectorTrain, vector<VectorBase> *masterVectorTest) {
    this->dio = dio;
    this->description = "display results";
    this->masterVectorTest = masterVectorTest;
    this->masterVectorTrain = masterVectorTrain;
}



void DisplayResults::execute() {
    if (this->masterVectorTest->empty()) {
        string emptyMessage = "please upload data";
        this->dio->write(emptyMessage);
    } else if (this->masterVectorTest->at(0).getStr().empty()) {
        string notClassified = "please classify the data";
        this->dio->write(notClassified);
    } else {
        string vectorSize = to_string(this->masterVectorTest->size());
        this->dio->write(vectorSize);
        int loopSize = (int)this->masterVectorTest->size();
        int i;
        for (i = 0; i < loopSize; i++) {
            string resultDisplay = to_string(i + 1) + "\t" + this->masterVectorTest->at(i).getStr();
            this->dio->write(resultDisplay);
        }
        string done = "Done.";
        this->dio->write(done);
    }
}