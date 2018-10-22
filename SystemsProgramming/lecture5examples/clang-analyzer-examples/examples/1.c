struct S {
  int x;
};

void f(struct S s){
}

void test() {
  struct S s;
  f(s); // warn: passed-by-value arg contain uninitialized data
}

int main(){
  test();
}
