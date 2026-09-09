// Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
// The program should have autodates

// Example:

// Date: 27th August 2026

// To: John Okello,

// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,


// John Doe
// Registra
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {

    // Declarations
    string firstName;
    string lastName;
    string program;
    string academicYear;

    // Input
    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    cout << "Enter your study program: ";
    getline(cin >> ws, program);

    cout << "Enter the academic year: ";
    cin >> academicYear;


    // Get current date
    time_t now = time(0);
    tm *localTime = localtime(&now);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon;
    int year = localTime->tm_year + 1900;

    string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };


    // Determine the suffix of the day
    string suffix;

    if (day % 100 >= 11 && day % 100 <= 13) {
        suffix = "th";
    }
    else if (day % 10 == 1) {
        suffix = "st";
    }
    else if (day % 10 == 2) {
        suffix = "nd";
    }
    else if (day % 10 == 3) {
        suffix = "rd";
    }
    else {
        suffix = "th";
    }


    // Output
    cout << "\nDate: " << day << suffix << " "
         << months[month] << " " << year << endl;

    cout << "\nTo: " << firstName << " " << lastName << "," << endl;

    cout << "\nDear " << firstName << "," << endl;

    cout << "\nCONGRATULATIONS! I am pleased to inform you that the Makerere University "
         << "Admissions Board has approved your application for admission to the "
         << academicYear << " academic year." << endl;

    cout << "\nYou have been offered a place for the following course:" << endl;

    cout << "PROGRAM: " << program << endl;

    cout << "\nAs a student of Makerere University, you will be part of a historic "
         << "institution dedicated to academic excellence and innovation. Please ensure "
         << "that you report to the Academic Registrar's office with your original "
         << "academic documents for verification during the orientation week." << endl;

    cout << "\nWe look forward to welcoming you to the Makerere University." << endl;

    cout << "\nYours sincerely," << endl;

    cout << "\n\nJohn Doe" << endl;
    cout << "Registra" << endl;

    return 0;
}
