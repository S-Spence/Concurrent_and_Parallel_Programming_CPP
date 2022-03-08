/* Pat finishes cooking while Sarah cleans */
#include <thread>
#include <chrono>

// A function to clean the kitchen
void kitchen_cleaner() {
    while (true) {
        printf("Sarah cleaned the kitchen.\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    // Initialize the sarah thread
    std::thread sarah(kitchen_cleaner);
    // This will create the sarah thread as a detached thread so it will not continue 
    // running once the pat thread is complete. 
    sarah.detach();
    // Pat thread is cooking
    for(int i = 0; i < 3; i++) {
        printf("Pat is cooking...\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
    // We do not need a join() function here because the sarah process is detached
    printf("Pat is done...\n");
}
