#include <random>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
// compute mean and median temperatures
{
    vector<double> temps;           // temperatures
    for (double temp; cin >> temp;) // read into temp
        temps.push_back(temp);      // put temp into vector

    // compute mean temperature:
    double sum = 0;
    for (double x : temps)
        sum += x;
    cout << "Average temperature: " << sum / temps.size() << '\n';

    // compute median temperature:
    sort(temps.begin(), temps.end()); // sort the temperatures

    double median = 0;
    if (temps.size() % 2 == 0)
        median = (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2.0;
    else
        median = temps[temps.size() / 2];

    cout << "Median temperature: " << median << '\n';
}

