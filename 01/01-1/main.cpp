#include <iostream>
#include "rotation_data.hpp"

int main() {
    
    int current_data {50}; // Initial pointer value
    int previous_data {current_data};
    int zero_crossing_counter {0};
    std::cout << "Initial pointer: " << current_data << std::endl;
    for (int i = 0; i < 4042; i++) {
        std::cout << "------------------------" << std::endl;
        std::cout << "Iteration number " << (i+1) << std::endl;
        std::cout << "pointer value before this iteration: " << current_data << std::endl;
        current_data = current_data + rotation_data[i];
        std::cout << "rotation data: " << rotation_data[i] << std::endl;
        current_data = (current_data % 100 + 100) % 100; // Wrap around to stay within [0, 99]
        std::cout << "pointer value after this iteration: " << current_data << std::endl;
        if (current_data == 0) {
            std::cout << "Found zero crossing at iteration: " << i << std::endl;
            zero_crossing_counter++;
            std::cout << "Number of zero crossings: " << zero_crossing_counter << std::endl;
        }
    }
    std::cout << "Total number of zero crossings: " << zero_crossing_counter << std::endl;
    return 0;
}