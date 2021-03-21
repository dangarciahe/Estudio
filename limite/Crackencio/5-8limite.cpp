#include <iostream>
#include <cmath>

typedef double REAL;

//Se inicializan las funciones
//Funcion porcentaje de error
REAL error(REAL teorico, REAL experimental);
REAL fx(REAL x);
REAL crecursion(REAL x, int n);

//Programa
int main()
{
  //inputs
  REAL x = 1.0;
  int n = 15;
  REAL exacto = 1.0/6.0;

  REAL recursion;
  REAL y;
  REAL an;
  REAL aux = x;
  std::cout.precision(8);
  std::cout.setf(std::ios::scientific);
  std::cout << "n \t \t Valor \t \t \t  Error normal \t \t \t  Error recursion \n \n";
  
  //parte a
  for (int ii=1; ii<=n; ii++)
    {
      recursion = 0.0;
      an = 1/6.0;
      for (int jj=1; jj<=15; jj++)
	{
	  recursion+=an;
	  an = crecursion(aux,ii);
	}
      aux = aux/10.0;
      y = fx(aux);
      std:: cout << ii << "\t \t"
		 << y << "\t \t"
		 << error (exacto,y) << "\t \t"
		 << error (exacto, recursion) << "\n";
    } 
  return 0;
}


//definicion de funciones

//porcentaje de error
REAL error (REAL teorico, REAL experimental)
{
  REAL valor = 100.0*fabs(teorico-experimental)/teorico;
  return valor;
}

//f(x)
REAL fx (REAL x)
{
  REAL valor;
  valor = (1/pow(x,2)) - ((sin(x))/(pow(x,3)));  
  return valor;
}

//coeficiente n+1 de la recursion
REAL crecursion (REAL x, int n)
{
  REAL valor;
  valor = (x*x)/((2*n+5)*(2*n+4));
  return valor;
}



