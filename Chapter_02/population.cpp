// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>
using namespace std;

int main() {
    const long long currentPopulation = 312032486;
    const long long secondsPerYear = 365LL * 24 * 60 * 60;
    const long long birthsPerYear = secondsPerYear / 7;
    const long long deathsPerYear = secondsPerYear / 13;
    const long long immigrantsPerYear = secondsPerYear / 45;
    const long long netChangePerYear = birthsPerYear - deathsPerYear + immigrantsPerYear;

    cout << "Year\tPopulation\n";

    for (int year = 1; year <= 5; ++year) {
        long long population = currentPopulation + netChangePerYear * year;
        cout << year << "\t" << population << endl;
    }

    return 0;
}


