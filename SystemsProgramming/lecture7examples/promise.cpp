#include <stdio.h>
#include <vector>
#include <thread>
#include <future>
#include <numeric>
 
void sum(std::vector<int>::iterator begin,
         std::vector<int>::iterator end,
         std::promise<int> sum_promise) {
  int sum = std::accumulate(begin, end, 0);
  sum_promise.set_value(sum);
}
 
int main() {
  auto numbers = std::vector<int>{ 1, 2, 3, 4, 5, 6 };
  std::promise<int> sum_promise;
  std::future<int> sum_future = sum_promise.get_future();
  auto t = std::thread(sum, numbers.begin(), numbers.end(), std::move(sum_promise));

  printf("result = %d\n", sum_future.get());

  t.join();
}