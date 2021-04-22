#include <random>
#include <iostream>

int main(int argc, char **argv)
{
  //inputs
  int xmin=0;
  int xmax=9;
  
  int N = std::atoi(argv[1]);
  int histograma[xmax-xmin] = {0};
  int aux = 0;
  std ::cout << "n \t Frecuencia \n \n";
  
  //std::random_device rd;  //Generar una seed aleatoria
  std::mt19937 gen(1); //Standard mersenne_twister_engine seeded with whatever seed it is inside gen(). Se llamara gen
  std::uniform_int_distribution <> distrib(xmin, xmax); //tipo de distribucion y limites. Se le llamara distrib

  for (int ii = 0; ii<N; ++ii)
    {
      aux = distrib(gen);
      histograma[aux-xmin] +=1;   
    }

  for (int jj = xmin; jj<= xmax; jj++)
    {
      std::cout << jj<< "\t \t"
		<< histograma[jj-xmin]<< "\n"; 
    }
  
    return 0;
}
