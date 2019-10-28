#include <memory>
#include <vector>

struct node {
  const char* value;
  std::vector< std::shared_ptr<struct node> > edges_to;

  node(const char * v) { value = v; }

  void add_edge_to(std::shared_ptr<struct node> n) {
    edges_to.push_back(n);
  }
};

int main() {
  std::shared_ptr<struct node> a = std::make_shared<struct node>("a");
  a->add_edge_to(std::make_shared<struct node>("b"));
  a->add_edge_to(std::make_shared<struct node>("c"));
  std::shared_ptr<struct node> d = std::make_shared<stuct node>("d");
  a->edges_to[0]->add_edge_to(d);
  a->edges_to[1]->add_edge_to(d);
}