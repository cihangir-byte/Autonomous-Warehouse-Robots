#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::MatrixXd X(2, 2);
    X << 1, 2,
         3, 4;
    Eigen::VectorXd y(2);
    y << 1,
         2;

    Eigen::VectorXd beta = X.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(y);
    
    std::cout << "The least-squares solution is:\n"
              << beta << std::endl;

    return 0;
}
