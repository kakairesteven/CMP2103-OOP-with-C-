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

// Function to get the current date with the correct day suffix (e.g., 27th August 2026)
std::string getAutoDate() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int day = now->tm_mday;
    int year = now->tm_year + 1900;

    // Array of month names
    std::string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    std::string month = months[now->tm_mon];

    // Determine day suffix (st, nd, rd, th)
    std::string suffix = "th";
    if (day < 11 || day > 13) {
        switch (day % 10) {
            case 1: suffix = "st"; break;
            case 2: suffix = "nd"; break;
            case 3: suffix = "rd"; break;
        }
    }

    return std::to_string(day) + suffix + " " + month + " " + std::to_string(year);
}

int main() {
    std::string firstName, lastName, studyProgram, academicYear;

    // Prompt user for input details
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter Study Program: ";
    std::getline(std::cin, studyProgram);

    std::cout << "Enter Academic Year (e.g., 2027/2028): ";
    std::getline(std::cin, academicYear);

    std::cout << "\n--------------------------------------------------\n\n";

    // Output the Admission Letter
    std::cout << "Date: " << getAutoDate() << "\n\n";
    std::cout << "To: " << firstName << " " << lastName << ",\n\n";
    std::cout << "Dear " << firstName << ",\n\n";
    std::cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n"
              << "Admissions Board has approved your application for admission to the\n"
              << academicYear << " academic year.\n\n";
              
    std::cout << "You have been offered a place for the following course:\n"
              << "PROGRAM: " << studyProgram << "\n\n";
              
    std::cout << "As a student of Makerere University, you will be part of a historic\n"
              << "institution dedicated to academic excellence and innovation. Please ensure\n"
              << "that you report to the Academic Registrar's office with your original\n"
              << "academic documents for verification during the orientation week.\n\n";
              
    std::cout << "We look forward to welcoming you to the Makerere University.\n\n";
    std::cout << "Yours sincerely,\n\n\n";
    std::cout << "John Doe\n"
              << "Registrar\n";

    return 0;
}
