#include <iostream>
#include <omp.h>

double f(double x);
double parallel_integral ();

//inputs
const double a = 0;
const double b = 10;
const long N = 1000000;
double deltax = (b-a)/N;

int main (){
  double integral = parallel_integral();
  std::cout <<integral<<"\n";
  return 0;
}


double f (double x){ //f(x)
  double valor = x*x;
  return valor;
}

double parallel_integral (){//paralelizacion de la integral
  double valor = 0;
#pragma omp parallel for reduction (+:valor)
  for (int ii=0; ii<N-1; ii++){
      double x = a + deltax*(ii+0.5);
      valor+=f(x);
    }
  valor *= deltax;
  return valor;
}

