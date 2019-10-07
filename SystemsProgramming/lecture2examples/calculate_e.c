#include <stdio.h>
#include <math.h>
    
#define EPSILON 1.0e-15
    
int main() {
  long fact = 1;
  double e = 2.0;
  int n = 2;
  double e0;

  double ep_float = EPSILON;
  int ep_int = EPSILON;
  printf("%f | %d\n", ep_float, ep_int);

  do {
    e0 = e;
    fact *= n++;
    e += 1.0 / fact;
  } while (fabs(e - e0) >= 1.0e-15);
  printf("e = %.15f\n", e);
}
