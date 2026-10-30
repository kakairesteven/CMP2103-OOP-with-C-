// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.


#include <iostream>
using namespace std;

int main(){
    long long currentPopulation = 312032486;
    int secondsInAYear = 365 * 24 * 60 * 60;
    int births = secondsInAYear / 7;// Number of births per year
    int deaths = secondsInAYear / 13;// Number of deaths per year
    int immigrants = secondsInAYear / 45;// Number of immigrants per year

    for (int year = 1; year <= 5; year++) {
        currentPopulation += (births - deaths + immigrants);
        cout << "Population after " << year << " year(s): " << currentPopulation << endl;
    }

    return 0;
}
