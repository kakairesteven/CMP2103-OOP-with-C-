#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string firstName, lastName, program, academicYear;

    // Get today's date automatically
    time_t now = time(0);
    tm *localTime = localtime(&now);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;

    // Get information from the user
    cout << "Enter your first name: ";
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    cout << "Enter your study program: ";
    getline(cin, program);

    cout << "Enter academic year: ";
    getline(cin, academicYear);

    // Display the acceptance letter
    cout << "\n\n";
    cout << "Date: " << day << "/" << month << "/" << year << "\n\n";

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