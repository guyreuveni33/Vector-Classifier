#ifndef EX3_AP_VECTORBASE_H
#define EX3_AP_VECTORBASE_H

#include <vector>
#include <string>

using namespace std;

//This is a class that represents a vector base.
class VectorBase {
private:
    string vectorClassification;
    vector<double> v;
    double algoDistance;
public:
/**
  * This function is a constructor for the VectorBase class.
  *
  * @param vectorClassification The name of the flower
  * @param v The vector of the flower
  * @param algoDistance The distance between the flower and the query flower.
  */
    VectorBase(string flowerName, vector<double> v, double algoDistance);

/**
 * This function returns the distance between the two vectors.
 *
 * @return The distance between the two vectors.
 */
    double getDistance();

/**
 * `string VectorBase::getStr()`
 *
 * The function returns a string. The function is a member of the VectorBase class. The function is called getStr
 *
 * @return The string vectorClassification is being returned.
 */
    string getStr();

/**
 * This function sets the vectorClassification variable to the value of the vectorClassification parameter.
 *
 * @param vectorClassification This is the classification of the vector.
 */
    void setStr(string vectorClassification);

/**
 * This function sets the algoDistance variable to the value of the parameter algoDistance.
 *
 * @param algoDistance The distance between the two points.
 */
    void setAlgoDistance(double algoDistance);

 /**
 * `int VectorBase::getDigitVectorSize()`
 *
 * The function returns an integer. The function is a member of the class VectorBase. The function is called
 * getDigitVectorSize. The function takes no arguments
 *
 * @return The size of the vector.
 */
    int getDigitVectorSize();

/**
 * This function returns the vector.
 *
 * @return A vector of doubles.
 */
    vector<double> getVector();

};

#endif
