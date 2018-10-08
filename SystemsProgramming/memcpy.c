#include <stdio.h>

void memorycopy(void * dst, const void * src, size_t count) {
  char * b_dst = (char *)dst;
  char * b_src = (char *)src;
  for (int i = 0; i < count; i++)
    b_dst[i] = b_src[i];
}

int main() {
  float f[] = {1, 2, 3};
  float g[3];

  memorycopy(g, f, 3);
}
