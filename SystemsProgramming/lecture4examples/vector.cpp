#include <vector>

int main() {
    std::vector<int> v(24);
    v[22] = 42;

    for(int i = 0; i < v.size(); i++) {
        printf("%d\n", v[i]);
    }
}
