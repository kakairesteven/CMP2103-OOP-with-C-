#include <iostream>
#include <string>
#include <ctime>

// Function to get ordinal suffix for a day (1st, 2nd, 3rd, 4th, etc.)
std::string getOrdinalSuffix(int day) {
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

// Function to fetch current date formatted as "27th August 2026"
std::string getCurrentFormattedDate() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int day = now->tm_mday;
    int year = now->tm_year + 1900;

    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return std::to_string(day) + getOrdinalSuffix(day) + " " + months[now->tm_mon] + " " + std::to_string(year);
}

int main() {
    std::string firstName, lastName, studyProgram, academicYear;

    // Prompt user input
    std::cout << "Enter First Name: ";
    std::cin >> firstName;

    std::cout << "Enter Last Name: ";
    std::cin >> lastName;

    // Clear buffer before using getline for multi-word inputs
    std::cin.ignore();

    std::cout << "Enter Study Program: ";
    std::getline(std::cin, studyProgram);

    std::cout << "Enter Academic Year (e.g., 2027/2028): ";
    std::getline(std::cin, academicYear);

    // Get current date automatically
    std::string currentDate = getCurrentFormattedDate();

    // Print acceptance letter
    std::cout << "\n------------------------------------------------------------\n\n";
    std::cout << "Date: " << currentDate << "\n\n";
    std::cout << "To: " << firstName << " " << lastName << ",\n\n";
    std::cout << "Dear " << firstName << ",\n\n";
    std::cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    std::cout << "Admissions Board has approved your application for admission to the\n";
    std::cout << academicYear << " academic year.\n\n";
    std::cout << "You have been offered a place for the following course:\n";
    std::cout << "PROGRAM: " << studyProgram << "\n\n";
    std::cout << "As a student of Makerere University, you will be part of a historic\n";
    std::cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    std::cout << "that you report to the Academic Registrar's office with your original\n";
    std::cout << "academic documents for verification during the orientation week.\n\n";
    std::cout << "We look forward to welcoming you to Makerere University.\n\n";
    std::cout << "Yours sincerely,\n\n\n";
    std::cout << "Lubega Ronald\n";
    std::cout << "Registrar\n";

    return 0;
}