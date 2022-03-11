/*
Too many philosophers create thread starvation
*/
#include <thread>
#include <mutex>
#include <array>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    int sushi_eaten = 0;
    
    while (sushi_count > 0){
        std::scoped_lock lock(chopsticks);
        // Decrement sushi count
        sushi_count--;
        sushi_eaten++;
    }
    // Print how many pieces this philosopher took
    printf("Philosopher %d took %d pieces.\n", std::this_thread::get_id(), sushi_eaten);
}

int main() {
    // initialize lock
    std::mutex chopsticks;
    // Initialize philosophers array
    std::array<std::thread, 200> philosophers;
    // Initialize philosopher threads
    for (size_t i = 0; i < philosophers.size(); i++) {
        philosophers[i] = std::thread(philosopher, std::ref(chopsticks));
    }
    // Wait for threads to complete
    // Initialize philosopher threads
    for (size_t i = 0; i < philosophers.size(); i++) {
        philosophers[i].join();
    }
    printf("The philosophers are done eating");



}
