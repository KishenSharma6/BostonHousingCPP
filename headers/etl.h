#ifndef etl_h
#define etl_h

#include <string>
#include <vector>
#include <eigen3/Eigen/Dense>

class ETL{

public:
    std::string filename;
    std::string delimiter;
    bool header;
    
    ETL(std::string dataset, std::string seperator, bool head):filename(dataset), delimiter(seperator), header(head){}; //constructor
    
    std::vector<std::vector<std::string>> ReadCSV(); 
    Eigen::MatrixXd CSVtoEigen(std::vector<std::vector<std::string>> dataString, int rows, int cols);
    std::tuple<Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > TrainTestSplit(Eigen::MatrixXd dataset, float train_size);


    auto Mean(Eigen::MatrixXd data) -> decltype(data.colwise().mean());
    auto Std(Eigen::MatrixXd dataset) -> decltype(((dataset.array().square().colwise().sum())/(dataset.rows()-1)).sqrt());
    
    Eigen::MatrixXd Normalize(Eigen::MatrixXd dataset);





};

#endif