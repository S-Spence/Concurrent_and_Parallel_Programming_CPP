/**
 * Two philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 5000;

// Demonstrate an abandoned lock
void philosopher(std::mutex &chopsticks) {
    while (sushi_count > 0) {
        // In this example, the philosophers share one mutex
        //chopsticks.lock();
        // Resolve the abandoned lock example by using a scoped lock
        std::scoped_lock lock(chopsticks);

        // Decrement sushi count
        sushi_count--;
        // An abandoned thread happens here because this thread never releases the lock
        if (sushi_count == 10) {
            printf("This philiosopher has had enough.\n");
            break;
        }

        // Release lock. Delete the unlock function when using a scoped lock because it unlocks autmatically
        //chopsticks.unlock();
    }
}

int main() {
    // Initialize mutex
    std::mutex chopsticks;
    // Initialize threads
    std::thread sarah(philosopher, std::ref(chopsticks));
    std::thread pat(philosopher, std::ref(chopsticks));
    // Wait for threads to finish
    sarah.join();
    pat.join();
    // Complete
    printf("The philosophers are done eating.\n");
}
