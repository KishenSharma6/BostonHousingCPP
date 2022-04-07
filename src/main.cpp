#include <iostream>
#include <vector>

#include "../headers/etl.h"

#include <eigen3/Eigen/Dense>


int main(int argc, char *argv[]){

    ETL etl(argv[1], argv[2], argv[3]);
    
    std::vector<std::vector<std::string>> dataset = etl.ReadCSV();

    int rows= dataset.size();
    int cols= dataset[0].size();

    Eigen::MatrixXd dataMat= etl.CSVtoEigen(dataset, rows, cols);

    etl.TrainTestSplit()
    return EXIT_SUCCESS;

}