#include <iostream>
#include <cmath>
#include <cstdlib>
#include <random>
#include <mpi.h>

void parallel(N); //the parallel code
void sum_results(double val, int pid, int np); //sums the counting of the Nc counted for each process
void pi(int count, int N); //prints an aproximated value of pi

int main(int argc, char**argv)
{
  int N = std::aoti(argv[0]);

  parallel(N);
  
  return 0;
}


void(N)
{
  
  MPI_Init(&argc, &argv); //initialization of the processes in parallel
  
  int pid; //variable which is going to be replaced by the number id of the current process
  int np; //variable which is going to be replaced by the total number of processes currently running
  
  MPI_Comm_size(MPI_COMM_WORLD &np); //total number of processes
  MPI_Comm_rank(MPI_COMM_WORLD, &pid); //id number of the current process
  
  int count = 0;
  int seed = pid; // use pid for seed when in parallel
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(-1.0, 1.0);

  double localsize = (1.0*N)/np
  
  for (int ii = 0; ii < N; ++ii) {
    double rx = dis(gen);
    double ry = dis(gen);
    if (rx*rx + ry*ry < 1)
      count++;
  }
  sum_results(count, pid, np);
  
  pi(count, N);
  
  MPI_Finalize(); //Ending of the parallel processes
}

void sum_results(double val, int pid, int np)
{
  int tag = 0;
  if (pid != 0) {
    // enviar val a pid 0
    int dest = 0;
    MPI_Send(&val, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  } else { // pid ==0
    // recibir de pid 1, 2, 3, 4, 5, ... , np-1
    double total = val;
    for (int ipid = 1; ipid < np; ++ipid) {
      MPI_Recv(&val, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total += val;
    }
    // imprimir
    std::cout << "Total value: " << total << std::endl;
  }
}

void pi (int nc, int n)
{
  double p =(4.0*nc)/n; //is important to do the multiplication by 4.0 first because nc and n are integers, therefore they can get truncated to cero because nc<n. 
  std::cout << 'An aproximated value of pi is given by:'  << '' << p << std::
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "mpi.h"

using fptr = double(double);

double f(double x);
double integral(double a, double b, int nsteps, fptr fun, int pid, int np);
void sum_results(double val, int pid, int np);

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv); /* Mandatory */

  int pid;                 /* rank of process */
  int np;                 /* number of processes */

  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  double a = std::atof(argv[1]);
  double b = std::atof(argv[2]);
  int N = std::atoi(argv[3]);;

  double t0 = MPI_Wtime();
  double val = integral(a, b, N, f, pid, np);
  double t1 = MPI_Wtime();
  std::cout << "TIME: " << t1-t0 << std::endl;
  
  sum_results(val, pid, np);

  
  
  MPI_Finalize(); /* Mandatory */
  
  return 0;
}


void sum_results(double val, int pid, int np)
{
  int tag = 0;
  if (pid != 0) {
    // enviar val a pid 0
    int dest = 0;
    MPI_Send(&val, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  } else { // pid ==0
    // recibir de pid 1, 2, 3, 4, 5, ... , np-1
    double total = val;
    for (int ipid = 1; ipid < np; ++ipid) {
      MPI_Recv(&val, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total += val;
    }
    // imprimir
    std::cout << "Total value: " << total << std::endl;
  }
}

double pi (int nc, int n)
{
  double p =(4.0*nc)/n; //is important to do the multiplication by 4.0 first because nc and n are integers, therefore they can get truncated to cero because nc<n. 
  return p;
}

