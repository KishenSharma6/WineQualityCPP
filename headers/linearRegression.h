#ifndef linearRegression_h
#define linearRegression_h

#include </opt/homebrew/include/eigen3/Eigen/Dense>

class LinearRegression
{
public:
    LinearRegression(){} // constructor

    float OLS_Cost(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta);
    std::tuple<Eigen::VectorXd, std::vector<float>> GradientDescent(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::VectorXd theta, float alpha, int iters);
    float RSquared(Eigen::MatrixXd y, Eigen::MatrixXd y_hat);


};

#endif