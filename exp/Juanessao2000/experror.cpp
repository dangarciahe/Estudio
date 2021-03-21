#include <iostream>
#include <cmath>

typedef double REAL; /*se declara este typedef por si se quiere hacer un cambio general de tipo de variable*/

/*DECLARACIÓN DE LAS FUNCIONES*/
REAL errorexp(REAL t, REAL x); /*Función que halla el error porcentual de la variable t respecto a la función exponencial*/
void recurtaylor(REAL x, int iter, REAL & an, REAL & sum); /*función que calcula la serie de Taylor mediante una relación recursiva que evita el overflow debido a los valores del factorial*/
REAL factorial(int iter); /*función que calcula el valor del factorial de un valor entero n/ lo hace conviertiendo
                         la variable n de entero a double en su interior (no sé si esto sea una manera tramposa de evitar under y overflows, no le entendí bien eso al profe)*/
void factaylor (REAL x, int iter, REAL & an, REAL & sum); /*función que calcula la serie de taylor mediante el factorial*/
void tstop (REAL t, REAL prec, int & stop);

const REAL eps = 10e-6; /*valor de la tolerancia*/

/*FUNCIÓN PRINCIPAL*/

int main()
{

  std::cout.precision(8); std::cout.setf(std::ios::scientific);

  /*DECLARACIÓN DE VARIABLE*/
  REAL n = 0;//número de la iteración / la iteración comienza en cero, con lo que n=24 es la 25ava iteración
  REAL rt = 0.0; /*Variable que se va a igualar con la forma recursiva de la serie de Taylor del exponencial*/
  REAL ft = 0.0; /*Variable que se va a relacionar con la forma con factorial de la serie de Taylor del exponencial*/
  int srt = 0; /*variable que determinará si rt sobrepasó la precisión*/
  int sft = 0; /*variable que determinará si ft sobrepasó la precisión*/
  REAL xe = 1; /*valor que le vamos a dar a x en la función f(x) = e^x*/


  REAL ntrt = 1.0; /*valor del n-ésimo término de la serie de Taylor con método de recurrencia*/
  REAL ntft = 1.0; /*valor del n-ésimo término de la serie de Taylor con método del factorial*/
  int NMAX = 25; /*máximo valor de iteraciones que queremos tener*/


  do{ /*realizo un do-while pues como tenemos una condición en la cual queremos que se detenga la iteración, aparte de un tope máximo, entonces un for no nos es suficiente para realizar el loop con lo que queremos*/
    recurtaylor(xe, n, ntrt, rt);
    factaylor (xe, n, ntft, ft);
    std::cout << n+1
              << "\t"
              << errorexp(rt, xe)
              << "\t"
              << errorexp(ft, xe)
              << "\n"; /*tabulación de las iteraciones y los errores de rt y ft respecto al valor del exponencial de acuerdo con la función dada por la librería cmath*/
    tstop(ntrt, eps, srt);
    tstop(ntft, eps, sft);

    n++;/*como le sumo 1 aquí, entonces en la condición tengo que restar dos para que me dé el correcto número de iteraciones;*/
  }while((n+2)<NMAX or (srt == 0 and sft == 0) );

}

///////////////////////////////////////////////////////////////////////////////////////////////
/*FUNCIONES AUXILIARES*/

void recurtaylor(REAL x, int iter, REAL & an, REAL & sum)
{
  if(iter == 0){sum == an;}
  else{
    an= an*x/iter;
    sum+= an;
  }
}

REAL factorial (int iter)
{
  REAL fac=1;
  for (REAL ii=1; ii<=iter; ii++)
  {
    fac*=ii;
  }
  return fac;
}

void factaylor (REAL x, int iter, REAL & an, REAL & sum)
{
  if(iter == 0){sum == an;}
  else
  {
    an = std::pow(x,iter)/factorial(iter);
    sum += an;
  }
}

REAL errorexp (REAL t, REAL x)
{
  REAL error = 0.0;
  error = std::fabs(t-std::exp(x))/std::exp(x); /*error de t respecto a std::exp*/
  return error;
}

void tstop (REAL t, REAL prec, int & stop)
{
  if(t < prec){stop = 1;}
  else{stop = 0;}
}
