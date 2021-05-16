#ifndef _MANUAL_PARALLEL_AVERAGE__
#define _MANUAL_PARALLEL_AVERAGE__

#include <iostream>
#include <vector>

typedef std::vector<double> vector;

void func(const std::vector<double> & data, int iimin, int iimax, double & result);
void parallel_sum (int N, int NTHREADS, double &sum, vector values);

#endif
