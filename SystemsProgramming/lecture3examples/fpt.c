#include <stdio.h>

int add(int x, int y) {return x + y;}
int sub(int x, int y) {return x - y;}

int main() {
  int (* op)(int, int) = add;

// if (...) {
//   op = &add;
// } else {
//   op = &sub;
// }

  int result = op(5, 6);
  printf("%d\n", result);
}