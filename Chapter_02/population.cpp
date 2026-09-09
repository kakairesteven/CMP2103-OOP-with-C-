#include <iostream>
using namespace std;

int main() {
    // Current population and total seconds in a 365-day year
    long long currentPopulation = 312032486;
    const double secondsInYear = 365.0 * 24 * 60 * 60; // 31,536,000 seconds

    // Rates in seconds per event
    const double birthRate_Seconds = 7.0;    // One birth every 7 seconds
    const double deathRate_Seconds = 13.0;   // One death every 13 seconds
    const double migrationRate_Seconds = 45.0; // One immigrant every 45 seconds

    // Calculate annual counts based on rates
    double births_PerYear = secondsInYear / birthRate_Seconds;
    double deaths_PerYear = secondsInYear / deathRate_Seconds;
    double immigrants_PerYear = secondsInYear / migrationRate_Seconds;

    // Annual net population change
    double netGainPerYear = births_PerYear - deaths_PerYear + immigrants_PerYear;

    // Calculate and display population for each of the next 5 years
    for (int year = 1; year <= 5; ++year) {
        currentPopulation += netGainPerYear;
        cout << "Year " << year << " population: " << currentPopulation << endl;
    }

    return 0;
}  


