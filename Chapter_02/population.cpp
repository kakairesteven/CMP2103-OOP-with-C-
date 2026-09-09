// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 

#include <iostream>
using namespace std;

int main() {
    // Standard starting population from the assignment (Change this number if needed)
    long long current_population = 312032486; 

    // Calculate total seconds in a 365-day year
    long long seconds_in_year = 365 * 24 * 60 * 60;

    // Calculate rates per year (using double or integer division depending on strict truncation rules)
    long long births_per_year = seconds_in_year / 7;
    long long deaths_per_year = seconds_in_year / 13;
    long long immigrants_per_year = seconds_in_year / 45;

    // Calculate net growth per year
    long long net_growth_per_year = births_per_year - deaths_per_year + immigrants_per_year;

    // Loop through the next 5 years and display updates
    for (int i = 1; i <= 5; i++) {
        current_population += net_growth_per_year;
        cout << "Year " << i << " population is: " << current_population << endl;
    }

    return 0;
}
