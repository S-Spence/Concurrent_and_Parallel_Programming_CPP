#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick){
    while(sushi_count > 0) {
        // Set lock
        first_chopstick.lock();

        // If the second chopstick cannot lock, release lock on first chopstick
        if (!second_chopstick.try_lock()){
            first_chopstick.unlock();
            // Causethe thread to wait to give the other threads a chance to grab the lock.
            std::this_thread::yield();
        } else {

            // Decrement count
            sushi_count--;

            // Release both locks
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
}

int main() {
    // Instantiate mutex locks
    std::mutex first_chopstick, second_chopstick;

    /* 
    * Create threads (Four threads creates a livelock, while two threads do not)
    * the livelock occurs with more than two threads because none of the philosophers
    * can aquire both locks at the same time. 
    */
    std::thread sarah(philosopher, std::ref(first_chopstick), std::ref(second_chopstick));
    std::thread pat(philosopher, std::ref(first_chopstick), std::ref(second_chopstick));
    std::thread angela(philosopher, std::ref(first_chopstick), std::ref(second_chopstick));
    std::thread jim(philosopher, std::ref(first_chopstick), std::ref(second_chopstick));

    // Wait for threads to finish
    sarah.join();
    pat.join();
    angela.join();
    jim.join();

    printf("The philosophers are done eating...\n");
}
