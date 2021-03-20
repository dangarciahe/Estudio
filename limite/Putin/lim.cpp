#include<iostream>
#include<cmath>

typedef double REAL;

REAL Rel_Diff (REAL real, REAL cal);
REAL f_x(REAL x);
REAL g_x(REAL x);
REAL Serie(REAL x);

int main ( int argc, char** argv)
{
    REAL real=(1.0/6.0);
    REAL xf=1.0;
    REAL x=std::atoi(argv[1]);
    std::cout.precision(10);
    std::cout.setf(std::ios::scientific);
    for (int ii=0; ii<16; ii++){
        std::cout<<ii+1<<"\t"<<Rel_Diff(real,Serie(xf))<<"\t"<<Rel_Diff(real,f_x(xf))<<"\t"<<"\t"<<Rel_Diff(real,g_x(xf))<<"\n";
        if (ii==0){
            xf=x;
        }
        else{
            xf=xf/10;
        }
    }
    return 0;
}

REAL Rel_Diff (REAL real, REAL clte)
{
    REAL Diff = std::fabs(real-clte)/real;
    return Diff;
}

REAL f_x(REAL x)
{
    REAL fx=(x-std::sin(x))/std::pow(x,3);
    return fx;
}

REAL g_x(REAL x)
{
    REAL gx=(1.0/std::pow(x,2))-std::sin(x)/std::pow(x,3);
    return gx;
}

REAL Serie(REAL x)
{
    REAL sum=(1.0/6.0)-(x*x)/120.0;
    return sum;
}
