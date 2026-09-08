#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Function to add the correct ordinal suffix
string getOrdinal(int day) {
    if (day >= 11 && day <= 13)
        return to_string(day) + "th";

    switch (day % 10) {
        case 1:
            return to_string(day) + "st";
        case 2:
            return to_string(day) + "nd";
        case 3:
            return to_string(day) + "rd";
        default:
            return to_string(day) + "th";
    }
}

int main() {
    string firstName, lastName, program, academicYear;

    // Get student's information
    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    // Clear the input buffer
    cin.ignore();

    cout << "Enter your study program: ";
    getline(cin, program);

    cout << "Enter the academic year: ";
    getline(cin, academicYear);

    // Get the current date automatically
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

    // Display the acceptance letter
    cout << "\n\n";
 
    cout << "                    MAKERERE UNIVERSITY\n";
    cout << "                    ACCEPTANCE LETTER\n";
    cout << "\n\n";

    cout << "Date: " << getOrdinal(day) << " "
         << months[month] << " " << year << "\n\n";

    cout << "To: " << firstName << " " << lastName << ",\n\n";

    cout << "Dear " << firstName << ",\n\n";

    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere\n";
    cout << "University Admissions Board has approved your application for\n";
    cout << "admission to the " << academicYear << " academic year.\n\n";

    cout << "You have been offered a place for the following course:\n";
    cout << "PROGRAM: " << program << "\n\n";

    cout << "As a student of Makerere University, you will be part of a historic\n";
    cout << "institution dedicated to academic excellence and innovation. Please\n";
    cout << "ensure that you report to the Academic Registrar's office with your\n";
    cout << "original academic documents for verification during the orientation week.\n\n";

    cout << "We look forward to welcoming you to the Makerere University.\n\n";

    cout << "Yours sincerely,\n\n";

    cout << "John Doe\n";
    cout << "Registrar\n";



    return 0;
}
