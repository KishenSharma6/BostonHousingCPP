#ifndef etl_h
#define etl_h

#include <string>

class ETL{

public:
    std::string filename;
    std::string delimiter;
    bool header;
    
    ETL(std::string dataset, std::string seperator, bool head):filename(dataset), delimiter(seperator), header(head){}; //constructor
    int Test();
    int CSVtoEigen();





};

#endif