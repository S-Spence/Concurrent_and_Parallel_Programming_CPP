/**
 * Two threads chopping vegetables
 */
#include <thread>
#include <chrono>

bool chopping = true;

void vegetable_chopper(const char* name) {
    unsigned int vegetable_count = 0;
    while (chopping) {
        vegetable_count++;
    }
    printf("%s chopped %u vegetables.\n", name, vegetable_count);
}

int main() {
    // Initialize threads
    std::thread sarah(vegetable_chopper, "Sarah");
    std::thread pat(vegetable_chopper, "Pat");
    // Sleep for one second 
	printf("Sarah and Pat are chopping vegetables...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // Set chopping to false
    chopping = false;
    // Wait for the first thread to finish
    sarah.join();
    pat.join();
}
