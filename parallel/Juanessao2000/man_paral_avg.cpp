#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include "pavg.h"

int main(int argc, char **argv) {
  const int N = std::atoi(argv[1]);
  const int NTHREADS = std::atoi(argv[2]);

  double sum = 0.0;
  std::vector<double> values(N);
  std::iota(values.begin(), values.end(), 1); // fill the vector with values 1, 2, 3 , ..., N-1
  parallel_sum(N, NTHREADS, sum, values);

  double avg = sum/N;

  std::cout << avg << '\n';

  return 0;
}
