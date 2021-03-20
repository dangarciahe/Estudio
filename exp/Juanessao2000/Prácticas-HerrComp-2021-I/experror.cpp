#include <iostream>
#include <cmath>

typedef double REAL;
REAL errorexp(REAL t);
REAL recurtaylor(REAL xe, int iter);


int main()
{
    int n = 0;//la iteración comienza en cero, por eso n=24 es la 25ava iteración

    do{
        std::cout << 100*std::fabs(recurtaylor(xe, n)-std::exp(xe))/std::exp(xe)
                  << "\t"
                  << 100*std::fabs(factaylor(xe, n)-std::exp(xe))/std::exp(xe)
                  << "\n";
        n++;/*como le sumo 1 aquí, entonces en la condición tengo que restar dos para que me dé el correcto número de iteraciones;*/
    }while((n-2));

}
