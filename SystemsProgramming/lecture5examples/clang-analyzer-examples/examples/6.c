
void test(int *p) {
  int x;
  if (p)
    return;

  x = p[0]; // warn
}

int main(){
  int * p = (int *)malloc(sizeof(int));
  test(p);
}
