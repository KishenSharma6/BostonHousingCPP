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


Eigen::MatrixXd ETL::CSVtoEigen(std::vector<std::vector<std::string>> dataset, int rows, int cols)
{
    /*converts dataset to eigen*/
    if(header==true)
    {
        rows = rows -1;
    }
    
    Eigen::MatrixXd mat(rows, cols);//init matrix to hold data in memory

    for (int i= 0; i< rows; i++){
        for (int j= 0; j < cols; j ++){
            mat(i, j) = atof(dataset[i][j].c_str());
        }
    }
    return mat;
}

std::tuple<Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > ETL::TrainTestSplit(Eigen::MatrixXd dataset, float train_size){
    int train_rows= dataset.rows() * train_size;
    int test_rows= dataset.rows() - train_rows;

    Eigen::MatrixXd x_train;
    Eigen::MatrixXd y_train;
    Eigen::MatrixXd x_test;
    Eigen::MatrixXd y_test

}

auto ETL::Mean(Eigen::MatrixXd dataset) -> decltype(dataset.rowwise().mean()
{
    return dataset.colwise().mean();
}

auto ETL::Std(Eigen::MatriXxd dataset) -> decltype(((dataset.array().square().colwise().sum())/(data.rows()-1)).sqrt())
{
    return ((dataset.array().square().colwise().sum())/(data.rows()-1)).sqrt();
}

