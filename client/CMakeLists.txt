cmake_minimum_required(VERSION 3.23)
project(ex4_AP)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex4_AP main.cpp VectorCreation.cpp VectorCreation.h Command.cpp Command.h DefaultIO.cpp DefaultIO.h SocketIO.cpp SocketIO.h UploadCSV.cpp UploadCSV.h SetAlgo.cpp SetAlgo.h)