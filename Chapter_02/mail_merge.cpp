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
// Registra#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Variables for student information
    string firstName, lastName, studyProgram, academicYear;

    // Get the student's information
    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    cin.ignore();

    cout << "Enter your study program: ";
    getline(cin, studyProgram);

    cout << "Enter your academic year: ";
    getline(cin, academicYear);

    // Get the current date automatically
    time_t now = time(0);
    tm *currentDate = localtime(&now);

    int day = currentDate->tm_mday;
    int month = currentDate->tm_mon + 1;
    int year = currentDate->tm_year + 1900;

    // Display the acceptance letter
    cout << "\n\n";
    cout << "Date: " << day << "/" << month << "/" << year << endl;
    cout << "\n";

    cout << "To: " << firstName << " " << lastName << "," << endl;
    cout << "\n";

    cout << "Dear " << firstName << "," << endl;
    cout << "\n";

    cout << "CONGRATULATIONS!" << endl;
    cout << "I am pleased to inform you that the Makerere University "
         << "Admissions Board has approved your application for admission "
         << "to the " << academicYear << " academic year." << endl;
    cout << "\n";

    cout << "You have been offered a place for the following course:" << endl;
    cout << "PROGRAM: " << studyProgram << endl;
    cout << "\n";

    cout << "As a student of Makerere University, you will be part of a "
         << "historic institution dedicated to academic excellence and "
         << "innovation. Please ensure that you report to the Academic "
         << "Registrar's office with your original academic documents "
         << "for verification during the orientation week." << endl;
    cout << "\n";

    cout << "We look forward to welcoming you to Makerere University." << endl;
    cout << "\n";

    cout << "Yours sincerely," << endl;
    cout << "\n\n";

    cout << "John Doe" << endl;
    cout << "Registrar" << endl;

    return 0;
}
