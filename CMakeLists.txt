cmake_minimum_required(VERSION 3.21.2)  
project(housing_regression)               
set(CMAKE_CXX_STANDARD 17)            


include_directories(headers)
include_directories("/opt/homebrew/include")

link_directories("/opt/homebrew/lib")

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/main.cpp
                 src/etl.cpp
                 headers/etl.h
                 src/linearRegression.cpp
                 headers/linearRegression.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(regressor ${SOURCE_FILES})