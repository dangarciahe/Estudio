//Compilar con mpic++ mpi_montecarlo_pi.cpp
//Correr con mpirun -np [# procesos] a.out 2000000000

#include <iostream>
#include <cmath>
#include "mpi.h"
#include <random>

int samples (int N, int pid);
void sum_results(double val, int pid, int np, int N);

int main(int argc, char **argv)
{
  std::cout.precision(14);
  std::cout.setf(std::ios::scientific);

  MPI_Init(&argc, &argv); /* Mandatory */
  
  int pid;                 //rank of process 
  int np;                 // total number of processes

  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  int N = std::atoi(argv[1]);

  // double t0 = MPI_Wtime(); //En caso de que se quiera medir el tiempo individual por cada proceso

  int n = N/np; //La cantidad de datos que le toca a cada proceso
  double val = samples(n, pid);
  sum_results(val, pid, np, N);
  
  //double t1 = MPI_Wtime();
  //std::cout << "TIME: " << t1-t0 << std::endl;
  
  MPI_Finalize(); /* Mandatory */
  return 0;
}


int samples(int n, int pid)
{
  int count = 0;
  int seed = pid; 
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(-1.0, 1.0);
  for (int ii = n*pid; ii < n*(pid+1); ++ii) { //Si se usa la misma seed en todos los procesos, no se estará haciendo lo mismo np veces
    double rx = dis(gen);
    double ry = dis(gen);
    if (rx*rx + ry*ry < 1)
      count++;
  }
  return count;
}


void sum_results(double val, int pid, int np, int N)
{
  int tag = 0;
  
  if (pid != 0) {    // enviar val a pid 0
    int dest = 0;
    MPI_Send(&val, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }
  else { //if  pid ==0, recibir de pid 1, 2, 3, 4, 5, ... , np-1  
    double total = val;
    for (int ipid = 1; ipid < np; ++ipid) {
      MPI_Recv(&val, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total += val;
    }   
    // Promediar, hallar pi e imprimir   
    double pi = 4.0*total/N;
    std::cout << "Pi is: " << pi << std::endl;
  }
}
