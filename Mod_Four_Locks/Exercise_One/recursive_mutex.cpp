/*
Two shoppers adding garlic and potatoes to a shared notepad
*/
#include <thread>
#include <mutex>

// Initialize garlic and potato counts
unsigned int garlic_count = 0;
unsigned int potato_count = 0;
// Initialize a recursive mutex to call the mutex lock in nested functions
std::recursive_mutex pencil;

// Define a function to increment garlic
void add_garlic() {
    // Set mutex lock before incrementing
    pencil.lock();
    garlic_count++;
    // Release lock
    pencil.unlock();
}

// Define a function to increment potatoes
void add_potato() {
    // Set mutex lock
    pencil.lock();
    potato_count++;
    // Nesting two calls to the lock function by adding garlic each time potatoes increment
    add_garlic();
    pencil.unlock();
}

// Create a shopper function
void shopper(){
    for (int i = 0; i < 10000000; i++){
        add_potato();
    }
}

int main() {
    // Initialize two shopper threads
    std::thread sarah(shopper);
    std::thread pat(shopper);

    sarah.join();
    pat.join();

    printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
}
