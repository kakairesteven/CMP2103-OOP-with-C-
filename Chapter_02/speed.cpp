// (Average speed) Assume a runner runs 14 kilometers in 45 minutes and 30 seconds.
// Write a program that displays the average speed in miles per hour. (Note that
// 1 mile is 1.6 kilometers.)

#include <iostream>
using namespace std;

int main() {
    const double KILOMETERS_PER_MILE = 1.6;
    const double distanceKm = 14.0;
    const double minutes = 45.0 + 30.0 / 60.0;
    const double hours = minutes / 60.0;

    double distanceMiles = distanceKm / KILOMETERS_PER_MILE;
    double averageSpeedMph = distanceMiles / hours;

    cout << "Average speed: " << averageSpeedMph << " miles per hour" << endl;

    return 0;
}

