/*
Demonstrate a deadlock between dining philosophers
*/
#include <mutex>
#include <thread>

int sushi_count = 5000;

// This philosopher function creates a deadlock
void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick){
    while (sushi_count > 0) {
        // Set mutex locks
        first_chopstick.lock();
        second_chopstick.lock();
        // Decrement sushi count
        sushi_count--;
        // Release locks
        first_chopstick.unlock();
        second_chopstick.unlock();

    }
}

int main() {
    // Initialize locks
    std::mutex chopstick_a, chopstick_b;
    // Initialize threads
    std::thread sarah(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    // The line below creates a deadlock because the threads prioritize different chopsticks
    //std::thread pat(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    // The line below resolves the above deadlock by ensuring the thread prioritize the same chopstick
    std::thread pat(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    
    // Wait for threads to finish
    sarah.join();
    pat.join();
    printf("The philosophers are done eating...\n");
}
