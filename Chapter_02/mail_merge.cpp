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
#include <iomanip>
using namespace std;

// Helper function to get the correct day suffix (st, nd, rd, th)
std::string getDaySuffix(int day) {
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

int main() {
    // Variables to store user input
    std::string firstName, lastName, studyProgram, academicYear;

    // User Input Prompts
    std::cout << "=========================================\n";
    std::cout << "  MAKERERE UNIVERSITY ADMISSIONS SYSTEM  \n";
    std::cout << "=========================================\n\n";

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter Study Program (e.g., Bachelor of Science in...): ";
    std::getline(std::cin, studyProgram);

    std::cout << "Enter Academic Year (e.g., 2027/2028): ";
    std::getline(std::cin, academicYear);

    // Fetching the Current System Date (Autodate)
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int day = now->tm_mday;
    int year = now->tm_year + 1900; // tm_year is years since 1900

    // Array of months for easy text conversion
    std::string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    std::string monthName = months[now->tm_mon];

    // Printing the Generated Acceptance Letter
    std::cout << "\n\n------------------ GENERATED LETTER ------------------\n\n";
    
    std::cout << "Date: " << day << getDaySuffix(day) << " " << monthName << " " << year << "\n\n";
    
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
              
    std::cout << "We look forward to welcoming you to Makerere University.\n\n";
    
    std::cout << "Yours sincerely,\n\n\n"
              << "John Doe\n"
              << "Registrar\n";

    std::cout << "\n------------------------------------------------------\n";

    return 0;
}
