#ifndef etl_h
#define etl_h

#include <string>
#include <vector>

class ETL{

public:
    std::string filename;
    std::string delimiter;
    bool header;
    
    ETL(std::string dataset, std::string seperator, bool head):filename(dataset), delimiter(seperator), header(head){}; //constructor
    
    std::vector<std::vector<std::string>> ReadCSV(); 
    Eigen::MatrixXd CSVtoEigen(std::vector<std::vector<std::string>> dataString, int rows, int cols);





};

#endif