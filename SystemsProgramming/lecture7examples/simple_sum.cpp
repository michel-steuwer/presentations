#include <stdio.h>
#include <vector>
#include <numeric>
#include <future>

int parallelSum(std::vector<int>::iterator begin, std::vector<int>::iterator end, int acc) {
  auto len = end - begin;
  // compute sequentially for small arrays
  if (len < 1000) { return std::accumulate(begin, end, 0); }
  auto mid = begin + len/2;
  // launch asynchronous task for the left half of the array
  auto left_side = std::async([=] { return parallelSum(begin, mid, acc); });
  // compute right half of array recursively
  int right_side   = parallelSum(mid, end, acc);
  // block to wait for left side to finish
  return left_side.get() + right_side;
}

int main() {
  auto vec = std::vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  auto sum = parallelSum(vec.begin(), vec.end(), 0);
  printf("sum: %d\n", sum);
}