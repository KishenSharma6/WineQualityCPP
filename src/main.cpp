#include "../headers/etl.h"

#include <iostream>
#include <string>
#include </opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3/Eigen/Dense>
#include </opt/homebrew/Cellar/boost/1.78.0_1/include/boost/algorithm/string.hpp>
#include <vector>


int main(int argc, char *argv[])
{
    ETL etl(argv[1], argv[2], argv[3]);

    std::vector<std::vector<std::string>> dataset = etl.readCSV();

    int rows = dataset.size();
    int cols= dataset[0].size();

    Eigen::MatrixXd datamat= etl.CSVtoEigen(dataset, rows, cols);

    Eigen::MatrixXd normalized_mat = etl.Normalize(datamat);

    std::cout << normalized_mat << std::endl;
    return EXIT_SUCCESS;
}