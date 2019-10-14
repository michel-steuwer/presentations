#include <stdio.h>

 int main() {
  unsigned char byte = 0;
  byte = byte | (1 << 3); // set the 3rd bit to 1
  printf("%d\n", byte);   // prints 8 (== 2^3)
}