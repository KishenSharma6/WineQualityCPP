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
    //Constructor
    ETL(std::string data, std::string seperator, bool head) : dataset(data), delimiter(seperator), header(head){}

    std::vector< std::vector< std::string>> readCSV();
    Eigen::MatrixXd CSVtoEigen(std::vector< std::vector < std::string>> dataset, int rows, int cols);

    auto Mean(Eigen::MatrixXd data) -> decltype(data.colwise().mean());
    auto Std(Eigen::MatrixXd data) -> decltype(((data.array().square().colwise().sum())/(data.rows() -1)).sqrt());

    Eigen::MatrixXd Normalize(Eigen::MatrixXd raw_data);
};

#endif