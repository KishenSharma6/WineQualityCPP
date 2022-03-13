#ifndef etl_h
#define etl_h

#include <iostream>
#include <fstream>
#include </opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3/Eigen/Dense>

class ETL
{
    std::string dataset;
    std::string delimiter;
    bool header;

public:
    ETL(std::string data, std::string seperator, bool head) : dataset(data), delimiter(seperator), header(head){}

    std::vector< std::vector< std::string > > readCSV();


};

#endif