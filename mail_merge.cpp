#include <iostream>
#include <string>
#include <ctime>

int main() {
    std::string fullName;
    std::string firstName;

    // Prompt user for their full name
    std::cout << "Enter your full name (e.g., John Okello): ";
    std::getline(std::cin, fullName);

    // Extract first name for the informal greeting ("Dear John,")
    size_t spaceIndex = fullName.find(' ');
    if (spaceIndex != std::string::npos) {
        firstName = fullName.substr(0, spaceIndex);
    } else {
        firstName = fullName; // Fallback if only one name is entered
    }

    // Automatically fetch current system date
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    char dateBuffer[100];
    // Formats date like: 03 September 2026
    std::strftime(dateBuffer, sizeof(dateBuffer), "%d %B %Y", now);

    // Print the acceptance letter
    std::cout << "\n--------------------------------------------------\n";
    std::cout << "Date: " << dateBuffer << "\n\n";
    std::cout << "To: " << fullName << ",\n\n";
    std::cout << "Dear " << firstName << ",\n\n";
    std::cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    std::cout << "Admissions Board has approved your application for admission to the\n";
    std::cout << "2027/2028 academic year.\n\n";
    std::cout << "You have been offered a place for the following course:\n";
    std::cout << "PROGRAM: Bachelor of Science in Computer and Communication Engineering\n\n";
    std::cout << "As a student of Makerere University, you will be part of a historic\n";
    std::cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    std::cout << "that you report to the Academic Registrar's office with your original\n";
    std::cout << "academic documents for verification during the orientation week.\n\n";
    std::cout << "We look forward to welcoming you to Makerere University.\n\n";
    std::cout << "Yours sincerely,\n\n\n";
    std::cout << "John Doe\n";
    std::cout << "Registrar\n";
    std::cout << "--------------------------------------------------\n";

    return 0;
}