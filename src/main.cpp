#include "../headers/etl.h"
#include "../headers/linearRegression.h"

#include <iostream>
#include <string>
#include </opt/homebrew/include/boost/algorithm/string.hpp>
#include </opt/homebrew/include/eigen3/Eigen/Dense>
#include <vector>


int main(int argc, char *argv[])
{
    ETL etl(argv[1], argv[2], argv[3]);
    LinearRegression lr;
    std::vector<std::vector<std::string>> dataset = etl.readCSV();

    int rows = dataset.size();
    int cols= dataset[0].size();

    Eigen::MatrixXd datamat= etl.CSVtoEigen(dataset, rows, cols);

    Eigen::MatrixXd normalized_mat = etl.Normalize(datamat);

    Eigen::MatrixXd X_train, y_train, X_test, y_test;
    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> split_data = etl.TrainTestSplit(normalized_mat, .8);
    std::tie(X_train, y_train, X_test, y_test) = split_data;

    Eigen::VectorXd vec_train = Eigen::VectorXd::Ones(X_train.rows());
    Eigen::VectorXd vec_test = Eigen::VectorXd::Ones(X_test.rows());

    X_train.conservativeResize(X_train.rows(), X_train.cols()+1);
    X_train.col(X_train.cols()-1) = vec_train;

    X_test.conservativeResize(X_test.rows(), X_test.cols()+1);
    X_test.col(X_train.cols()-1) = vec_test;

    Eigen::VectorXd theta = Eigen::VectorXd::Zero(X_train.cols());
    float alpha = 0.01;
    int iters = 1000;

    Eigen::VectorXd thetaOut;
    std::vector<float> cost;

    std::tuple<Eigen::VectorXd,std::vector<float>> gd = lr.GradientDescent(X_train, y_train, theta, alpha, iters);
    std::tie(thetaOut,cost) = gd;

    std::cout << "Theta: " << thetaOut << std::endl; // view parameters
    std::cout << "\nLoss:\n" ;
    for(auto v: cost){
        std::cout << v << std::endl;
    }


    return EXIT_SUCCESS;
}