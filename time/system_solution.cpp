#include <iostream>
#include <chrono>
#include <ctime>
#include <eigen3/Eigen/Dense>

//typedef Eigen::EigenSolver<Eigen::Matrix<double,-1,-1>> solver;
typedef Eigen::VectorXd solver;

solver eigen_v(const Eigen::MatrixXd &m, const Eigen::VectorXd &v, int n);
  
int main(int argc, char **argv)
{

  std::chrono::time_point<std::chrono::system_clock> start, end;
  int N = std::atoi(argv[1]);
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(N,N);
  Eigen::VectorXd v = Eigen::VectorXd::Random(N);

  //timer
  start = std::chrono::system_clock::now(); //start timer
  auto solution = eigen_v(m, v, N);
  end = std::chrono::system_clock::now(); //end timer
  
  std::chrono::duration<double> elapsed_seconds = end - start;

  
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n \n \n";
  std::cout << solution << std::endl;
  
}


solver eigen_v(const Eigen::MatrixXd &m, const Eigen::VectorXd &v, int n){
  Eigen::VectorXd x(n);
  x = m.colPivHouseholderQr().solve(v);
  return x;
}
