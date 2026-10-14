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

// Function to get the current date formatted nicely (e.g., 8th September 2026)
string getCurrentDate() {
    time_t t = time(0);
    tm* now = localtime(&t);
    
    int day = now->tm_mday;
    int year = now->tm_year + 1900;
    
    string months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    string month = months[now->tm_mon];
    
    // Determine the day suffix (st, nd, rd, th)
    string suffix = "th";
    if (day == 1 || day == 21 || day == 31) suffix = "st";
    else if (day == 2 || day == 22) suffix = "nd";
    else if (day == 3 || day == 23) suffix = "rd";
    
    return to_string(day) + suffix + " " + month + " " + to_string(year);
}

int main() {
    string fullName, firstName, programName;

    // Prompt user for input details
    cout << "Enter the student's full name (e.g., John Okello): ";
    getline(cin, fullName);

    cout << "Enter the student's first name (e.g., John): ";
    getline(cin, firstName);

    cout << "Enter the degree program (e.g., Bachelor of Science in Computer and Communication Engineering): ";
    getline(cin, programName);

    // Generate and display the letter
    cout << "\n---------------------------------------------------------\n";
    cout << "Date: " << getCurrentDate() << "\n\n";
    cout << "To: " << fullName << ",\n\n";
    cout << "Dear " << firstName << ",\n\n";
    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    cout << "Admissions Board has approved your application for admission to the\n";
    cout << "2027/2028 academic year.\n\n";
    cout << "You have been offered a place for the following course:\n";
    cout << "PROGRAM: " << programName << "\n\n";
    cout << "As a student of Makerere University, you will be part of a historic\n";
    cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    cout << "that you report to the Academic Registrar's office with your original\n";
    cout << "academic documents for verification during the orientation week.\n\n";
    cout << "We look forward to welcoming you to the Makerere University.\n\n";
    cout << "Yours sincerely,\n\n";
    cout << "John Doe\n";
    cout << "Registra\n";
    cout << "---------------------------------------------------------\n";

    return 0;
}