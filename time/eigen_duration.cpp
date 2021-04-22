#include <iostream>
#include <chrono>
#include <ctime>
#include <Eigen/Eigenvalues>
//#include <eigen3/Eigen/Dense>


typedef Eigen::EigenSolver<Eigen::Matrix<double,-1,-1>> solver; 

solver eigen_v(const Eigen::MatrixXd &m);
  
int main(int argc, char **argv)
{
  
  std::chrono::time_point<std::chrono::system_clock> start, end;

  int N = std::atoi(argv[1]);
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(N,N);
  // Eigen::MatrixXd ones = Eigen::MatrixXd::Ones (N,N); //linea desechada

  start = std::chrono::system_clock::now(); //start timer
  //funcion a medir
  auto sol = eigen_v(m);
  end = std::chrono::system_clock::now(); //end timer
  std::chrono::duration<double> elapsed_seconds = end - start;
  
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  //std::cout << sol.eigenvectors().col(0)<< std::endl;
  
}


solver eigen_v(const Eigen::MatrixXd &m){
  Eigen::EigenSolver<Eigen::MatrixXd> sol(m, false);
  
  return sol;
}
