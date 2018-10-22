void test() {
  void (*foo)(void);
  foo(); // warn: function pointer is uninitialized
}

int main(){
  test();
}
