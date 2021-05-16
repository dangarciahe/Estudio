#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include "pavg.h"

void func(const vector  & data, int iimin, int iimax, double & result)
{
  result = 0;
  for (int ii = iimin; ii < iimax; ++ii) {
    result += std::sqrt(std::sqrt(data[ii]));
  }
}

void parallel_sum (int N, int NTHREADS, double &sum, vector values)
{
std::vector<std::thread> mythreads(NTHREADS);
  vector vals(NTHREADS, 0.0); // store here partial sums
  for (int ii = 0; ii < NTHREADS; ++ii) {
    const int localsize = N/NTHREADS; // how much size for each thread, NTHREADS must be divisor of N
    const int iimin = localsize*ii; // FILL HERE minimum global index for this thread
    const int iimax = localsize*(ii+1); // FILL HERE maximim global index for this thread
    mythreads[ii] = std::thread(&func, values, iimin, iimax, std::ref(vals[ii]));
  }
  for (int ii = 0; ii < NTHREADS; ++ii) {
    mythreads[ii].join();
  }
  sum =  std::accumulate(vals.begin(), vals.end(), 0.0); // assigns the accumulated sum
}
