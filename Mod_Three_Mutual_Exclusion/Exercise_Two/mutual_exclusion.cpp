/*
Two shoppers adding items to a shared notepad, mutual exclusion
*/

#include <thread>
#include <mutex>
#include <chrono>

unsigned int garlic_count = 0;
// Initialize a mutex value
std::mutex pencil;

void shopper() {
    // Increment garlix count 5 times
    for (int i = 0; i < 5; i++){
        // Print a message and make the current thread sleep for half a second
        printf("Shopper %d is thinking...\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // Increment garlic count with a mutex lock
        pencil.lock();
        garlic_count++;
        // Release the lock
        pencil.unlock();
    }
}

int main(){
    // Initialize two shopper threads
    std::thread sarah(shopper);
    std::thread pat(shopper);
    // Tell the threads to wait for the other thread to complete
    sarah.join();
    pat.join();
    // Determine how much garlic to buy
    printf("We should buy %u garlic.\n", garlic_count);
}
