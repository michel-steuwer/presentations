void test(int z) {
  int x;
  if (z == 0)
    x = 1 / z; // warning: Division by zero
}

int main(){
  test(0);
}
