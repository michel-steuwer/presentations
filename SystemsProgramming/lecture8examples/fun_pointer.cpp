#include <stdio.h>
#include <functional>

void foo() {
  printf("foo!\n");
}

int main() {
  void (* function_pointer )() = foo;
  function_pointer();

  std::function<void()> f = foo;
  f();
}