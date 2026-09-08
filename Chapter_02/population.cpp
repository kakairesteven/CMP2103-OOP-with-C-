#include <iostream>

int main() {
    // Initial values
    long currentPopulation = 312032486;
    const int secondsPerYear = 365 * 24 * 60 * 60; // 31,536,000 seconds

    // Calculate annual rates
    int birthsPerYear = secondsPerYear / 7;
    int deathsPerYear = secondsPerYear / 13;
    int immigrantsPerYear = secondsPerYear / 45;

    // Net change in population each year
    int annualPopulationChange = birthsPerYear - deathsPerYear + immigrantsPerYear;

    // Display population for each of the next 5 years
    std::cout << "Initial Population: " << currentPopulation << "\n\n";

    for (int year = 1; year <= 5; ++year) {
        currentPopulation += annualPopulationChange;
        std::cout << "Year " << year << " Population: " << currentPopulation << "\n";
    }

    return 0;
}