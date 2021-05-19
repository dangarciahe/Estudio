#include <iostream>
#include <cmath>
#include <omp.h>

void fill_data(double *a, int size);
double averange(double *a, int size);

int main (int argc, char *argv[])
{
  const int N = 80000000;
  double *a = new double[N];
  fill_data(a, N);
  std::cout<<a[2]<<"\n";
  double avg=averange(a, N);
  std::cout<<avg<<"\n";
  delete [] a;
  return 0;
}


void fill_data(double *a, int size){
#pragma omp parallel
  {
    long int i;
    int thid = omp_get_thread_num();
    int nth = omp_get_num_threads();
    int thsize = size/nth;    
    for (i=thid*thsize; i<thsize*(thid+1) ; i++){
      a[i] = 2*i*std::sin(std::sqrt(i/56.7)+
      			std::cos(std::pow(i*i,0.3)));
      //a[i]=i;
    }
  }
  //#pragma omp barrier
}

double averange(double *a, int size){

  double result=0;
#pragma omp parallel
  {
    double sum=0;
    int i;
    int thid = omp_get_thread_num();
    int nth = omp_get_num_threads();
    int bsize = size/nth;      
    int imin = thid*bsize;
    int imax = imin+bsize;      
    for(i=imin; i<imax; i++){
      sum+=a[i];
    }
#pragma omp atomic
    result+=sum;
  }
  
  result=result/size;
  return result; 
}
