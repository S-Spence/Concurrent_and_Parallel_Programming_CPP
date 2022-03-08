/**
 * Several users reading a calendar, but only a few users updating it
 */
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <array>

// Initialize day values and number
char WEEKDAYS[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int today = 0;
// Initialize a shared mutex
std::shared_mutex marker;

// Create a function to read the calendar only
void calendar_reader(const int id) {
    
    for (int i=0; i<7; i++) {
        // Lock the shared mutex
        marker.lock_shared();
        // Display the date and sleep
        printf("Reader-%d sees today is %s\n", id, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // Release lock
		marker.unlock_shared();	
    }
}

// Create a function to write to the calendar
void calendar_writer(const int id) {

    for (int i=0; i<7; i++) {
        // Lock the mutex
        marker.lock();
        // Set the date today
        today = (today + 1) % 7;
        printf("Writer-%d updated date to %s\n", id, WEEKDAYS[today]);
        // Sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // Release the mutex lock
        marker.unlock();        
    }
}

int main() {
    // create ten reader threads and two writer threads
    std::array<std::thread, 10> readers;
    for (unsigned int i=0; i<readers.size(); i++) {
        readers[i] = std::thread(calendar_reader, i);
    }
    std::array<std::thread, 2> writers;
    for (unsigned int i=0; i<writers.size(); i++) {
        writers[i] = std::thread(calendar_writer, i);
    }

    // Wait for readers and writers to finish
    for (unsigned int i=0; i<readers.size(); i++) {
        readers[i].join();
    }
    for (unsigned int i=0; i<writers.size(); i++) {
        writers[i].join();
    }
}
