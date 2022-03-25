#include <iostream>
#include <fstream>
#include <vector>

#include "../headers/etl.h"
#include </opt/homebrew/include/boost/algorithm/string.hpp>


std::vector<std::vector<std::string>> ETL::ReadCSV()
{
    std::fstream file(filename);
    std::vector<std::vector<std::string>> dataString;
    
    std::string line= ""; // will hold string of text

    while (getline(file, line)){ //read from raw_data, store in line until raw_data ends
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimiter));
        dataString.push_back(vec);
    }

    file.close();

    return dataString;
}