// This program prints a calendar for a given month and year.
// Concepts covered include: functions, loops, and conditionals.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// Function declarations
void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void getMonthBody(int year, int month);

string getMonthName(int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberofDaysInMonth(int year, int month);
bool isLeapYear(int year);


// Check whether a year is a leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0)
           || (year % 400 == 0);
}


// Return the name of a month
string getMonthName(int month)
{
    switch (month)
    {
        case 1:
            return "January";

        case 2:
            return "February";

        case 3:
            return "March";

        case 4:
            return "April";

        case 5:
            return "May";

        case 6:
            return "June";

        case 7:
            return "July";

        case 8:
            return "August";

        case 9:
            return "September";

        case 10:
            return "October";

        case 11:
            return "November";

        case 12:
            return "December";

        default:
            return "Invalid Month";
    }
}


// Get the number of days in a month
int getNumberofDaysInMonth(int year, int month)
{
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if (isLeapYear(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }

        default:
            return 0;
    }
}


// Calculate the total number of days
// from January 1, 1800 to the beginning
// of the previous month
int getTotalNumberOfDays(int year, int month)
{
    int totalDays = 0; 

    // Add days for complete years
    for (int i = 1800; i < year; i++)
    {
        if (isLeapYear(i))
        {
            totalDays += 366;
        }
        else
        {
            totalDays += 365;
        }
    }

    // Add days for complete months
    for (int i = 1; i < month; i++)
    {
        totalDays += getNumberofDaysInMonth(year, i);
    }

    return totalDays;
}


// Return the day of the week on which
// the month begins
//
// 0 = Sunday
// 1 = Monday
// 2 = Tuesday
// ...
// 6 = Saturday
int getStartDay(int year, int month)
{
    int totalDays = getTotalNumberOfDays(year, month);

    // January 1, 1800 was Wednesday
    // Wednesday = 3
    return (totalDays + 3) % 7;
}


// Print the month title
void printMonthTitle(int year, int month)
{
    cout << "\n";

    cout << "       "
         << getMonthName(month)
         << " "
         << year
         << endl;

    cout << "---------------------------"
         << endl;

    cout << "Sun Mon Tue Wed Thu Fri Sat"
         << endl;
}


// Print the days of the month
void getMonthBody(int year, int month)
{
    int startDay = getStartDay(year, month);

    int numberOfDays =
        getNumberofDaysInMonth(year, month);


    // Print spaces before the first day
    for (int i = 0; i < startDay; i++)
    {
        cout << setw(4) << " ";
    }


    // Print all days
    for (int day = 1; day <= numberOfDays; day++)
    {
        cout << setw(3) << day << " ";


        // Move to next line after Saturday
        if ((day + startDay) % 7 == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
}


// Print the complete month
void printMonth(int year, int month)
{
    printMonthTitle(year, month);

    getMonthBody(year, month);
}


// Main function
int main()
{
    int year;
    int month;


    cout << "Enter a year: ";
    cin >> year;


    cout << "Enter a month (1-12): ";
    cin >> month;


    // Validate input
    if (month < 1 || month > 12)
    {
        cout << "Invalid month. Please enter a month between 1 and 12."
             << endl;

        return 1;
    }


    // Print calendar
    printMonth(year, month);


    return 0;
}


// Try
// Rewrite this program using if statements instead of switch statements for the getMonthName and getNumberofDaysInMonth functions.
// Explain the abstration of the program and state why it is important to use functions in this program.
// Draw a diagram to illustration abstraction levels in this program using a top-down approach.