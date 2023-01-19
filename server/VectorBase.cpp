#include "VectorBase.h"

/**
  * This function is a constructor for the VectorBase class.
  *
  * @param vectorClassification The name of the flower
  * @param v The vector of the flower
  * @param algoDistance The distance between the flower and the query flower.
  */
VectorBase::VectorBase(std::string vectorClassification, vector<double> v, double algoDistance) {
    this->vectorClassification = vectorClassification;
    this->v = v;
    this->algoDistance = algoDistance;

}

/**
 * This function returns the distance between the two vectors.
 *
 * @return The distance between the two vectors.
 */
double VectorBase::getDistance() {
    return algoDistance;
}

/**
  * The function is a member of the class `VectorBase` and returns a string
  *
  * @return The vectorClassification string.
  */
string VectorBase::getStr() {
    return vectorClassification;
}

int VectorBase::getDigitVectorSize() {
    return (int)v.size();
}
vector<double> VectorBase::getVector(){
    return v;
}
void VectorBase:: setStr(string vectorClassification ){
    this->vectorClassification=vectorClassification;
}
void VectorBase::setAlgoDistance(double algoDistance){
    this->algoDistance=algoDistance;
}