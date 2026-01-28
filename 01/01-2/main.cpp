#include <iostream>
#include "rotation_data.hpp"
#include <cmath>

int main() {
    
    constexpr int ITERATION_COUNT {sizeof(rotation_data)/sizeof(rotation_data[0])};
    int current_data {50}; // Initial pointer value
    int previous_data {current_data};
    int zero_crossing_counter {};
    int full_rounds_counter {};
    int partial_rounds_counter {};
    int reminder_value {};
    std::cout << "Initial pointer: " << current_data << std::endl;
    for (size_t i = 0; i < ITERATION_COUNT; i++) {
        std::cout << "------------------------" << std::endl;
        std::cout << "Iteration number " << (i+1) << std::endl;
        std::cout << "pointer value before this iteration: " << current_data << std::endl;
        current_data = current_data + rotation_data[i];
        std::cout << "rotation data: " << rotation_data[i] << std::endl;
        current_data = (current_data % 100 + 100) % 100; // Wrap around to stay within [0, 99]
        std::cout << "pointer value after this iteration: " << current_data << std::endl;
        std::cout << std::endl;
        std::cout << "Zero crossing calculation:" << std::endl;
        reminder_value = rotation_data[i] % 100;
        if ((previous_data + reminder_value) <= 0) { // Calculate crossing zero in this iteration without full loop being counted
            if (previous_data == 0) { // If starting at zero, this zero crossing is already counted
                partial_rounds_counter = 0;
            } else {
                partial_rounds_counter = 1;
            }
        } else if ((previous_data + reminder_value) >= 100) {
            partial_rounds_counter = 1;
        } else {
            partial_rounds_counter = 0;
        }
        full_rounds_counter = (abs(rotation_data[i]) / 100); // Number of full rounds
        std::cout << "Full rounds this iteration: " << full_rounds_counter << std::endl;
        std::cout << "Partial rounds this iteration: " << partial_rounds_counter << std::endl;
        zero_crossing_counter = zero_crossing_counter + full_rounds_counter + partial_rounds_counter;
        std::cout << "Number of zero crossings so far: " << zero_crossing_counter << std::endl;
        previous_data = current_data;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Total number of zero crossings: " << zero_crossing_counter << std::endl;

    return 0;
}