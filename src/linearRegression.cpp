#include "../headers/linearRegression.h"

#include <iostream>
#include <cmath>
#include <vector>
#include </opt/homebrew/include/eigen3/Eigen/Dense>

float LinearRegression::OLS_Cost(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta){
    Eigen::MatrixXd inner= pow(((X*theta) - y).array(), 2);

    return (inner.sum()/(2 * X.rows()));
}

std::tuple<Eigen::VectorXd, std::vector<float>> LinearRegression::GradientDescent(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::VectorXd theta, float alpha, int iters){

    Eigen::MatrixXd temp= theta;

    int parameters= theta.rows(); // number of features in the 

    std::vector<float> cost;
    cost.push_back(OLS_Cost(X, y, theta));

    for(int i= 0;i < iters; i++ ){
        Eigen::MatrixXd error= X * theta -y;
        for(int j=0; j < parameters; j++){
            Eigen::MatrixXd X_i = X.col(j);
            Eigen::MatrixXd term = error.cwiseProduct(X_i);
            temp(j,0) = theta(j,0) - ((alpha/X.rows()) * term.sum());
        }
        theta= temp;
        cost.push_back(OLS_Cost(X, y, theta));
    }
    return std::make_tuple(theta, cost);
}