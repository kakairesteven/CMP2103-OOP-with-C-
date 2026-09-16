#include <iostream>
#include <iomanip> // For std::setw and std::left

int main() {
    // Print the header with column widths of 8 characters
    std::cout << std::left 
              << std::setw(8) << "a" 
              << std::setw(8) << "a^2" 
              << std::setw(8) << "a^3" 
              << "\n";

    // Loop from a = 1 to a = 4
    for (int a = 1; a <= 4; ++a) {
        std::cout << std::left 
                  << std::setw(8) << a 
                  << std::setw(8) << (a * a) 
                  << std::setw(8) << (a * a * a) 
                  << "\n";
    }

    return 0;
}