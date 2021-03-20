#include<iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
typedef double REAL;

void recursive(REAL  x, int & ii, REAL & sum );
void Taylor (REAL x, int & jj, REAL & sum);
REAL Rel_Diff(REAL x, REAL y);
REAL Abs_Diff(REAL x, REAL y);
int fac(int n);

int main (int argc, char **argv)
{
    std::vector<REAL> values;
    values={0.0, 1.0,-1.0,-0.123,-25.5, 0.5, 3.14159};
    REAL exp=0.0;
    REAL x=0.0;
    REAL Tsum;
    REAL Rsum;
    int n;
    int m;
    std::cout.precision(10);
    std::cout.setf(std::ios::scientific);
    std::cout<<"x"<<"\t"<<"\t"<<"\t"<< "n" << "\t" << "R_error" << "\t"<< "\t"<<  "\t"<<"A_error" <<"\n";

    for (int ii=0; ii<values.size();ii++){
        x=values[ii];
        exp=std::exp(x);
        Taylor(x,m,Tsum);
        recursive(x,n,Rsum);
        if (x>0){
        std::cout<<x <<"\t"<< m+1 <<"\t" <<Rel_Diff(Tsum,exp)<<"\t"<< Abs_Diff(Tsum,exp)<<"\n";
        std::cout<<"\t"<<"\t"<<"\t"<< n+1 <<"\t" <<Rel_Diff(Rsum,exp)<<"\t"<< Abs_Diff(Rsum,exp)<<"\n";
        }
        else{
            x=-x;
            exp=std::exp(x);
            Taylor(x,m,Tsum);
            recursive(x,n,Rsum);
            std::cout<<-x<<"\t"<< m+1 <<"\t" <<Rel_Diff((1/Tsum),(1/exp))<<"\t"<< Abs_Diff((1/Tsum),(1/exp))<<"\n";
            std::cout<<"\t"<<"\t"<<"\t"<<n+1<<"\t" <<Rel_Diff((1/Rsum),(1/exp))<<"\t"<< Abs_Diff((1/Rsum),(1/exp))<<"\n";
        }

 }
    return 0;
}


int fac(int n)
{
    int fact=1;

    for (int ii=1; ii<=n; ii++){
        fact*=ii;
    }

    return fact;
}


void Taylor (REAL x, int & jj, REAL & sum)
{
    sum=1.0;
    jj=0;
    REAL t=1.0;

    while (t>10e-6 & jj<25){
        jj+=1;
        t=std::pow(x,jj)/fac(jj);
        sum+=t;
    }
}

 void recursive(REAL  x, int & ii, REAL & sum )
 {
     REAL a_n=1.0;
     sum=1.0;
     ii=0;

    while (a_n>10e-6 & ii<25){
        a_n=(x/(ii+1))*a_n;
        sum+=a_n;
        ii+=1;
    }
}

REAL Rel_Diff(REAL x, REAL y)
{
    REAL RD=std::fabs(x-y)/y;
    return RD;
}

REAL Abs_Diff(REAL x, REAL y)
{
    REAL AD=std::fabs(x-y);
    return AD;
}
