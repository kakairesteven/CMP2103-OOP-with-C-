// (Print a table) Write a program that displays the following table: Hint: without loops
// a	 	a^2		a^3
// 1 	 	1 		1
// 2 	 	4 		8
// 3  	 	9 		27
// 4 		16 		64

#include <iostream>
using namespace std;

int main() {
    // Print the header and each specific row directly
    std::cout << "a\t" << "a^2\t" << "a^3\n";
    std::cout << 1 << "\t" << 1 * 1 << "\t" << 1 * 1 * 1 << "\n";
    std::cout << 2 << "\t" <<  2 * 2 << "\t" <<  2 * 2 * 2 << "\n";
    std::cout << 3 << "\t" <<  3 * 3 << "\t" <<  3 * 3 * 3 << "\n";
    std::cout << 4 << "\t" <<  4 * 4 << "\t" <<  4 * 4 * 4 << "\n";
}

// Try
// Modify this program to use loops and string formating



// Compile std to be found by g++
// g++-16 -std=c++23 -fmodules -fsearch-include-path -c bits/std.cc

// Compile code
// g++-16 -std=c++23 -fmodules multiplication_table.cpp -o output/multiplication_table && output/multiplication_table