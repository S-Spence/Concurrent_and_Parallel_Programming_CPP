#include <thread>
#include <chrono>

void chef_sarah() {
    printf("Sarah started and is waiting for chicken to thaw...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Sarah is done cutting chicken.\n");
}

int main(){
    // Create a new chef sarah object
    printf("Pat requests Sarah's help...\n");
    std::thread sarah(chef_sarah);
    // Determine if the new thread is active
    printf("   Sarah is joinable? %s\n", sarah.joinable() ? "true" : "false");

    // Pat continues cooking soup that is represented by sleeping for one second
    printf("Pat continues cooking soup...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // Determine if the sarah thread is active
    printf("   Sarah is joinable? %s\n", sarah.joinable() ? "true" : "false");
    // the join function causes the pat thread to wait for sarah thread to finish before proceeding
    printf("Pat waits for sarah to finish and join\n");
    sarah.join();

    // joinable should return false now
    printf("   Sarah is joinable? %s\n", sarah.joinable() ? "true" : "false");

    // Both threads are done
    printf("Both threads are done.");
}
