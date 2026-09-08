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

int main() {
    std::string firstName, lastName, program, academicYear;

    // 1. Inputs
    std::cout << "Enter first name: ";  std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";   std::getline(std::cin, lastName);
    std::cout << "Enter program: ";     std::getline(std::cin, program);
    std::cout << "Enter academic year: "; std::getline(std::cin, academicYear);

    // 2. Auto-date calculation (Format: DD/MM/YYYY)
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    
    std::string date = std::to_string(now->tm_mday) + "/" + 
                       std::to_string(now->tm_mon + 1) + "/" + 
                       std::to_string(now->tm_year + 1900);

    // 3. Output Letter
    std::cout << "\nDate: " << date << "\n";
    std::cout << "To: " << firstName << " " << lastName << ",\n\n";
    std::cout << "Dear " << firstName << ",\n\n";
    std::cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    std::cout << "Admissions Board has approved your application for admission to the\n";
    std::cout << academicYear << " academic year.\n\n";
    std::cout << "You have been offered a place for the following course:\n";
    std::cout << "PROGRAM: " << program << "\n\n";
    std::cout << "As a student of Makerere University, you will be part of a historic\n";
    std::cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    std::cout << "that you report to the Academic Registrar's office with your original\n";
    std::cout << "academic documents for verification during the orientation week.\n\n";
    std::cout << "We look forward to welcoming you to Makerere University.\n\n";
    std::cout << "Yours sincerely,\n\nJohn Doe\nRegistrar\n";

    return 0;
}
