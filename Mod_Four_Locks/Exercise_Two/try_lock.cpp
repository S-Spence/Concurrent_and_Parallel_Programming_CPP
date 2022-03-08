/**
 * Two shoppers adding items to a shared notepad
 */
#include <thread>
#include <mutex>
#include <chrono>

// Initialize the length of the notepad and a mutex lock
unsigned int items_on_notepad = 0;
std::mutex pencil;

void shopper(const char* name) {
    int items_to_add = 0;
    // Only add 20 items to the notepad
    while (items_on_notepad <= 20) {
        if (items_to_add && pencil.try_lock()) {
            // Add items to notepad
            items_on_notepad += items_to_add;
            printf("%s added %u item(s) to notepad.\n", name, items_to_add);
            // Reset items to add count
            items_to_add = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(300)); // time spent writing
            // Release the lock
            pencil.unlock();
        } else { 
            // Look for other things to buy
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // time spent searching
            items_to_add++;
            printf("%s found something else to buy.\n", name);
        }
    }
}

int main() {
    // Initialize two new threads
    std::thread sarah(shopper, "Sarah");
    std::thread pat(shopper, "Pat");
    // Set the start time
    auto start_time = std::chrono::steady_clock::now();
    // Wait for the next thread to finish before proceeding
    sarah.join();
    pat.join();
    // Determine how much time elapsed
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
    printf("Elapsed Time: %.2f seconds\n", elapsed_time/1000.0);
}
