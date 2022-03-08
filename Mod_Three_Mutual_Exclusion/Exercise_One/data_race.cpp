/*
Two shoppers add items to a shared notepad
*/

#include <thread>

unsigned int garlic_count = 0;

// Define a shopper function to increment garlic
// Ten loops does not create a data race. However, 10 mil will show the effect of the data race.
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

    printf("We should buy %u garlic.\n", garlic_count);
}
