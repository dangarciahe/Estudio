#include <iostream>
#include <cmath>

typedef double REAL;

//Se definen las funciones que se usaran

//Funcion factorial
int factorial (int n)
{
  int fac=1;
  for (int ii=1; ii<=n; ii++)
    {
      fac*=ii;      
    }
    return fac;
}

//Coeficiente i-esimo de la serie
REAL cseries (REAL x, int n) 
{
  REAL valor = 0;
  valor = pow(fabs(x),n)/factorial(n); //fabs para usar el reciproco si x es negativo 
  return valor;
}

//Coeficiente i+1-esimo de la recursion
REAL crecursion(REAL x, int n, REAL an)
{
  REAL valor = 0;
  valor = an*fabs(x)/(n+1);
  return valor;
}

//funcion porcentaje de error
REAL error(REAL teorico, REAL exp)
{
  REAL valor = 0;
  valor = 100*fabs(teorico-exp)/teorico;
  return valor;
}



//Programa
int main ()
{
  //Inputs
  REAL x = 3.14159; //x en el que se evalua la funcion e^x
  int Nmax = 25;  // cota superior para el numero de pasos
  REAL tol = 10e-6; //La tolerancia

  //Se inicializan valores
  REAL series = 0;  
  REAL recursion = 0;
  REAL an = 1;
  REAL exacto = exp(x);
  int check1 = 0;//verificar tolerancia
  int check2 = 0; 
  std::cout << "n \t" << "Error series \t \t \t" << "Error recursion \n \n";
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  int ii=0;

  while ((ii<=Nmax-1) and (check1==0 or check2==0))
    {
      //Series
      REAL aux1 = cseries (x,ii);
      if (fabs(aux1)<tol)
	{
	  check1+=1;
	}
      series+=aux1;

      //Recursion
      recursion+=an;
      an = crecursion(x, ii, an);
      if (fabs(an)<tol)
	{
	  check2+=1;
	}	

      //Se usa el reciproco si x<0
      if (x<0)
	{
	  REAL series0 = 1/series;
	  REAL recursion0 = 1/recursion;	    
	  //Se imprime el resultado
	  std::cout << ii+1 << "\t"
		    << error (exacto, series0) << "\t \t"
		    << error (exacto, recursion0) << "\n";
	}
      std::cout << ii+1 << "\t"
		<< error (exacto, series) << "\t \t"
		<< error (exacto, recursion) << "\n";
      
      
      ii+=1;
    }
  return 0;
}
