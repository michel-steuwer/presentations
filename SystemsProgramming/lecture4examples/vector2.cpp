#include <vector>
#include <memory>

int main() {
  int n = 42;
  std::vector<int> xs = {1, 2, 3, 4, 5, 6, 7};
  xs.push_back(8);

  int * ptr = &n; // raw-pointer
  std::unique_ptr<int> uptr = std::make_unique<int>(42);
  std::shared_ptr<int> sptr = std::make_shared<int>(42);

} // end of xs, uptr, sptr lifetimes