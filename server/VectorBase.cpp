#include "VectorBase.h"


VectorBase::VectorBase(std::string vectorClassification, vector<double> v, double algoDistance) {
    this->vectorClassification = vectorClassification;
    this->v = v;
    this->algoDistance = algoDistance;

}

double VectorBase::getDistance() {
    return algoDistance;
}

string VectorBase::getStr() {
    return vectorClassification;
}


int VectorBase::getDigitVectorSize() {
    return (int) v.size();
}

vector<double> VectorBase::getVector() {
    return v;
}

void VectorBase::setStr(string vectorClassification) {
    this->vectorClassification = vectorClassification;
}

void VectorBase::setAlgoDistance(double algoDistance) {
    this->algoDistance = algoDistance;
}