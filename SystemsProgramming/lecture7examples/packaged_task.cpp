#include <stdio.h>
#include <math.h>

#include <thread>
#include <future>
 
int main() {
    auto task = std::packaged_task<int(int,int)>([](int a, int b) {
        return pow(a, b); 
    });
    std::future<int> result = task.get_future();
 
    // task(2, 10);
    auto t = std::thread(std::move(task), 2, 10);
    t.join();
 
    printf("task result: %d\n", result.get());
}