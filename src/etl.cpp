#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../headers/etl.h"
#include <boost/algorithm/string.hpp>
#include <eigen3/Eigen/Dense>



std::vector<std::vector<std::string>> ETL::ReadCSV()
{
    /*Reads csv data into memory as vector of vector of strings*/
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

void ETL::CorrectDataFormatting(std::vector<std::vector<std::string>> inputData, std::string outputFile)
{
    /*Corrects formatting issue of data/housing.csv and writes
    data/houseingCleaned.txt*/
    std::fstream file;
    file.open(outputFile, std::fstream::out);

    for (int i= 0; i < inputData.size(); i++)
    {
        file << inputData[i] << ",";
        file<< std::endl;

    }
    file.close();
    
}

Eigen::MatrixXd ETL::CSVtoEigen(std::vector<std::vector<std::string>> dataset, int rows, int cols)
{
    if(header==true)
    {
        rows = rows -1;
    }
    
    Eigen::MatrixXd mat(cols, rows);//init matrix to hold data in memory

    for (int i= 0; i< rows; i++){
        for (int j= 0; j < cols; j ++){
            mat(j, i) = atof(dataset[i][j].c_str());
        }
    }
    return mat.transpose();
}