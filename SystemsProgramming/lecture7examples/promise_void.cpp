#include <stdio.h>

#include <vector>
#include <thread>
#include <future>
#include <chrono>
 
void do_work(std::promise<void> barrier)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("Work done, signal now\n");
    barrier.set_value();
}
 
int main()
{
    std::promise<void> barrier;
    std::future<void> barrier_future = barrier.get_future();
    auto t = std::thread(do_work, std::move(barrier));
    printf("Start waiting for signal\n");
    barrier_future.wait();
    printf("Waiting finished, signal received\n");
    t.join();
}