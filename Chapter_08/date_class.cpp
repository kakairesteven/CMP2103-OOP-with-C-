#include <iostream>
using namespace std;

// simple Date (too simple?)
//struct Date {
  // int y;    // year
 //   string m; // month in year
  //  int d;    // day of month
 //};

struct Date
{
    int y, m, d;               // year, month, day
    Date(int y, int m, int d); // check for valid date and initialize
    void add_day(int n)        // increase the Date by n days
    {
        d += n;
    }
};

int main()
{
    Date now; // a Date variable (a named object)
    now.y = 2026;
     now.m = "September";
    now.d = 30;



    // Define a function that gets age

    cout << "Today is " << now.y << ", " << now.m << " " << now.d << "th\n";
    cout << "Tomorrow's date is " << now.y << ", " << now.m << ", " << now.add_day(now.d) << "th\n";
}

// struct X {
// int m;
// // ...
// };

// class X {
// public:
// int m;
// // ...
// };
