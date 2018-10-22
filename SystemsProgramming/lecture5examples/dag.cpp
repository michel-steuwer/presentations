#include <stdio.h>
#include <memory>
#include <vector>

struct node {
    const char * value;
    std::vector< std::shared_ptr<node> > edges_to;

    node(const char * v) {
        value = v;
    }

    void add_edge_to(std::shared_ptr<node> n) {
        edges_to.push_back(n);
    }
};

std::shared_ptr<node> create_diamond() {
  std::shared_ptr<node> a = std::make_shared<node>("a");
  a->add_edge_to(std::make_shared<node>("b"));
  a->add_edge_to(std::make_shared<node>("c"));
  std::shared_ptr<node> d = std::make_shared<node>("d");
  a->edges_to[0]->add_edge_to(d);
  a->edges_to[1]->add_edge_to(d);
  return a;
}

void print(const std::shared_ptr<node> ptr, int level) {
  if (ptr) {
    for (int i = 0; i < ptr->edges_to.size(); i++) {
      printf("%*s", level, "");
      printf("%s -> %s\n", ptr->value, ptr->edges_to[i]->value);
      print(ptr->edges_to[i], level + 1);
    }
  }
}

int main() {
  std::shared_ptr<node> d1 = create_diamond();

  print(d1, 0);
  printf("---\n");

  std::shared_ptr<node> d2 = create_diamond();
  d1->edges_to[0]->edges_to[0]->add_edge_to(d2);

  print(d1, 0);
  printf("---\n");
}
