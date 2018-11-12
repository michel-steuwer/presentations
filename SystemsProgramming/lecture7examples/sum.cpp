#include <stdio.h>
#include <vector>
#include <chrono>
#include <future>
#include <algorithm>
#include <random>
#include <numeric>
#include <iterator>

float randInt() {
  static std::default_random_engine generator;
  static std::uniform_int_distribution<int> distribution(0, 10);
  return distribution(generator);
}

int parallelSum(std::vector<int>::iterator begin,
                std::vector<int>::iterator end,
                int acc,
                int depth = 0) {
  auto len = end - begin;
  if (len < 1000 || depth > 3) { return std::accumulate(begin, end, 0); }
 
  auto mid = begin + len/2;
  auto left_side = std::async(std::launch::async,
    [=] { return parallelSum(begin, mid, acc, depth + 1); });
  int right_side   = parallelSum(mid, end, acc, depth + 1);
  return left_side.get() + right_side;
}

int main() {
  auto size = 1 * 1024 * 1024;
  auto vec = std::vector<int>(size);
  std::generate(vec.begin(), vec.end(), randInt);

  {
    auto start = std::chrono::high_resolution_clock::now();
    auto sum = std::accumulate(vec.begin(), vec.end(), 0);
    auto end = std::chrono::high_resolution_clock::now();
    printf("sum: %d (time: %f ms)\n", sum, std::chrono::duration<double, std::milli>(end - start).count());
  }
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto sum = parallelSum(vec.begin(), vec.end(), 0);
    auto end = std::chrono::high_resolution_clock::now();
    printf("par_sum: %d (time: %f ms)\n", sum, std::chrono::duration<double, std::milli>(end - start).count());
  }
}