/*
Two shoppers add items to a shared notepad with atomic objects
*/

#include <thread>
#include <atomic>

// Initialize the count variable and an atomic object
std::atomic<unsigned int> garlic_count(0);

// Define a shopper function to increment garlic
void shopper() {
    for (int i = 0; i < 10000000; i++) {
        garlic_count++;
    }
}

int main() {
    // Initialize two shopper threads
    std::thread sarah(shopper);
    std::thread pat(shopper);

    sarah.join();
    pat.join();
    // Call the atomic object's .load() function to read its stored value
    printf("We should buy %u garlic.\n", garlic_count.load());
}
