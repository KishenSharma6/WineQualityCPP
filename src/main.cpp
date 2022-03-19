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

    Eigen::MatrixXd X_train, y_train, X_test, y_test;
    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> split_data = etl.TrainTestSplit(normalized_mat, .8);
    std::tie(X_train, y_train, X_test, y_test) = split_data;

    std::cout << "X_train rows: " << X_train.rows() << std::endl;
    std::cout << "X_train cols: " << X_train.cols() << std::endl;
    std::cout << "y_train rows: " << y_train.rows() << std::endl;
    std::cout << "y_train cols: " << y_train.cols() << std::endl;

    std::cout << "X_test rows: " << X_test.rows() << std::endl;
    std::cout << "X_test cols: " << X_test.cols() << std::endl;
    std::cout << "y_test rows: " << y_test.rows() << std::endl;
    std::cout << "y_test cols: " << y_test.cols() << std::endl;
    return EXIT_SUCCESS;
}