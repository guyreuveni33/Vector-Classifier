cmake_minimum_required(VERSION 3.23)
project(ex4_AP)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex4_AP main.cpp VectorCreation.cpp VectorCreation.h MasterDistance.cpp
        MasterDistance.h Minkowski.cpp Minkowski.h Euclidean.cpp Euclidean.h Manhattan.cpp Manhattan.h
        Canberra.cpp Canberra.h Chebyshev.cpp Chebyshev.h VectorBase.cpp VectorBase.h CsvReading.h CsvReading.cpp
        Command.cpp UploadCSV.cpp UploadCSV.h SetAlgo.cpp SetAlgo.h ClassifyData.cpp ClassifyData.h DisplayResults.cpp
        DisplayResults.h DownloadResults.cpp DownloadResults.h Command.h SocketIO.cpp SocketIO.h DefaultIO.cpp DefaultIO.h CLI.cpp CLI.h)
