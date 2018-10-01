#include <stdio.h>

int main() {
  char greeting[] = "Hello world";
  printf("%s\n", greeting);

  char greeting2[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
  printf("%s\n", greeting2);
}