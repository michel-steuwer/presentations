#include <thread>
// #include <atomic>
// std::atomic<int> Global;
int Global;

int main() {
  auto t = std::thread([]{ Global = 42; });
  Global = 43;
  t.join();
  return Global;
}