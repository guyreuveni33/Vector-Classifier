//
// Created by oem on 1/16/23.
//

#include "SetAlgo.h"
#include "UploadCSV.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "CsvReading.h"
#include "Minkowski.h"

SetAlgo::SetAlgo(DefaultIO *dio) {
    this->dio = dio;
    this->description = "algorithm settings";
}
void SetAlgo::execute() {

}

