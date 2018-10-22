#include <stdio.h>
#include <memory>
#include <vector>

struct node {
    const char * value;
    std::vector< std::unique_ptr<node> > children;

    node(const char * v) { value = v; }

    void add_child(std::unique_ptr<node> n) {
        //children.push_back(std::move(n));
        children.push_back(n);
    }
};

std::unique_ptr<node> create_diamond() {
  std::unique_ptr<node> a = std::make_unique<node>("a");
  std::unique_ptr<node> b = std::make_unique<node>("b");
  std::unique_ptr<node> c = std::make_unique<node>("c");
  std::unique_ptr<node> d = std::make_unique<node>("d");

  b->add_child(std::move(d));

  a->add_child(std::move(b));
  a->add_child(std::move(c));
  // b->add_child(std::move(d)); // segfault
  //c->add_child(std::move(d)); // forbidden

  return a;
}

void print(const std::unique_ptr<node>* ptr, int level) {
  if (ptr && *ptr) {
    for (int i = 0; i < (*ptr)->children.size(); i++) {
      printf("%*s", level, "");
      printf("%s -> %s\n", (*ptr)->value, (*ptr)->children[i]->value);
      print(& (*ptr)->children[i], level + 1);
    }
  }
}

int main() {
  std::unique_ptr<node> d1 = create_diamond();

  print(&d1, 0);
  printf("---\n");

  std::unique_ptr<node> d2 = create_diamond();
  d1->children[0]->children[0]->add_child(std::move(d2));

  print(&d1, 0);
  printf("---\n");
}
