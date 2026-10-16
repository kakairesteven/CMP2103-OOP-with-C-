// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.


#include <iostream>

int main() {
    // Initial values based on 365 days a year
    long long population = 312032486;
    long long secondsInYear = 365 * 24 * 60 * 60;

    // Calculate annual numbers using integer division
    long long birthsPerYear = secondsInYear / 7;
    long long deathsPerYear = secondsInYear / 13;
    long long immigrantsPerYear = secondsInYear / 45;

    // Net growth rate per year
    long long netGrowthPerYear = birthsPerYear - deathsPerYear + immigrantsPerYear;

    std::cout << "Population Projections:\n";
    std::cout << "Current Population: " << population << "\n\n";

    // Loop to calculate and display population for each of the next 5 years
    for (int year = 1; year <= 5; year++) {
        population += netGrowthPerYear;
        std::cout << "Year " << year << ": " << population << "\n";
    }

    return 0;
}
