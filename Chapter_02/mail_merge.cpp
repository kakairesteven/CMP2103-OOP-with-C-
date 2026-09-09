#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Function to get the ordinal suffix for a given day (st, nd, rd, th)
string getDaySuffix(int day) {
    if (day >= 11 && day <= 13) {
        return "th";
    }
    switch (day % 10) {
        case 1:  return "st";
        case 2:  return "nd";
        case 3:  return "rd";
        default: return "th";
    }
}

// Function to generate today's date formatted as "27th August 2026"
string getFormattedDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    int day = ltm->tm_mday;
    int year = 1900 + ltm->tm_year;

    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    string monthStr = months[ltm->tm_mon];
    string suffix = getDaySuffix(day);

    return to_string(day) + suffix + " " + monthStr + " " + to_string(year);
}

int main() {
    string firstName, lastName, program, academicYear;

    // Prompt user input
    cout << "Enter your First Name: ";
    cin >> firstName;

    cout << "Enter your Last Name: ";
    cin >> lastName;

    cin.ignore(); // Clear buffer before reading line with spaces
    cout << "Enter Study Program (e.g., Bachelor of Science in Computer Engineering): ";
    getline(cin, program);

    cout << "Enter Academic Year (e.g., 2027/2028): ";
    getline(cin, academicYear);

    cout << "\n--------------------------------------------------\n\n";

    // Generate current date automatically
    string currentDate = getFormattedDate();

    // Print Acceptance Letter
    cout << "Date: " << currentDate << "\n\n";
    cout << "To: " << firstName << " " << lastName << ",\n\n";
    cout << "Dear " << firstName << ",\n\n";
    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    cout << "Admissions Board has approved your application for admission to the\n";
    cout << academicYear << " academic year.\n\n";
    cout << "You have been offered a place for the following course:\n";
    cout << "PROGRAM: " << program << "\n\n";
    cout << "As a student of Makerere University, you will be part of a historic\n";
    cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    cout << "that you report to the Academic Registrar's office with your original\n";
    cout << "academic documents for verification during the orientation week.\n\n";
    cout << "We look forward to welcoming you to the Makerere University.\n\n";
    cout << "Yours sincerely,\n\n\n";
    cout << "John Doe\n";
    cout << "Registrar\n";

    return 0;
}


Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
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