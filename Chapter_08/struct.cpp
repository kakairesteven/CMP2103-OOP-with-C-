// A struct has public members by default.

#include <iostream>
#include <string>
using namespace std;

// simple Date (too simple?)
// struct Date
// {
//     int y;    // year
//     string m; // month in year
//     int d;    // day of month
// };

struct Date
{
    int y, d;
    string m;

    // Date() : y{2026}, m{"July"}, d{6} {} // Initialize values
    Date(int y, string m, int d)
        : y{6}, m{"Oct"}, d{13}
    {
    }

    int add_day(int n) // increase the Date by n days
    {
        d += n;
        return d;
    }
};

int main()
{
    Date now = Date{2026, "Oct", 7}; // a Date variable (a named object)

    // Change accessible values
    now.y = 2026;
    now.m = "September";
    // now.d = 30;

    // Define a function that gets age

    std::cout << "Today is " << now.y << ", " << now.m << " " << now.d << "th\n";
    std::cout << "Tomorrow's date is " << now.y << ", " << now.m << " " << now.add_day(1) << "th\n";
}
