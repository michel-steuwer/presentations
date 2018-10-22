#include <stdio.h>
#include <stdlib.h>
#include <memory>

struct node {
    const char * value;
    std::unique_ptr<node> left_child;
    std::unique_ptr<node> right_child;
    node * parent;
    
    node(const char* value_) {
        value = value_;
        left_child = NULL;
        right_child = NULL;
        parent = NULL;
    }

    void add_left_child(const char* value_) {
        left_child = std::make_unique<node>(value_);
        left_child->parent = this;
    }

    void add_right_child(const char* value_) {
        right_child = std::make_unique<node>(value_);
        right_child->parent = this;
    }
};


int main() {
    node root("b");
    root.add_left_child("a");
    root.add_right_child("c");
    root.right_child->add_left_child("d");
    root.right_child->add_right_child("e");
}
