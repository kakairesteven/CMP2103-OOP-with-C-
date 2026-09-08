// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>

int main() {

    long population = 312032486;
    const long secondsPerYear = 365L * 24 * 60 * 60; // 31,536,000

    for (int year = 1; year <= 5; year++) {
        long births = secondsPerYear / 7;
        long deaths = secondsPerYear / 13;
        long immigrants = secondsPerYear / 45;

        population += births - deaths + immigrants;

        std::cout << "Year " << year << ": " << population << std::endl;
    }

    return 0;
}

