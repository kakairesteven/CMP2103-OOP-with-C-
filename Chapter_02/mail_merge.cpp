#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    string firstName;
    string lastName;
    string program;
    int academicYear;

    time_t now = time(0);
    tm *currentDate = localtime(&now);

    int day = currentDate->tm_mday;
    int month = currentDate->tm_mon + 1;
    int year = currentDate->tm_year + 1900;

    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    cin.ignore();

    cout << "Enter Study Program: ";
    getline(cin, program);

    cout << "Enter Academic Year: ";
    cin >> academicYear;

    cout << "\nDate: " << day << " " << months[month - 1] << " " << year << endl;

    cout << "\nTo: " << firstName << " " << lastName << "," << endl;

    cout << "\nDear " << firstName << "," << endl;

    cout << "\nCONGRATULATIONS! I am pleased to inform you that the "
         << "Makerere University Admissions Board has approved your "
         << "application for admission to the "
         << academicYear << "/" << academicYear + 1
         << " academic year." << endl;

    cout << "\nYou have been offered a place for the following course:" << endl;

    cout << "PROGRAM: " << program << endl;

    cout << "\nAs a student of Makerere University, you will be part of a historic "
         << "institution dedicated to academic excellence and innovation. "
         << "Please ensure that you report to the Academic Registrar's office "
         << "with your original academic documents for verification during the "
         << "orientation week." << endl;

    cout << "\nWe look forward to welcoming you to Makerere University." << endl;

    cout << "\nYours sincerely," << endl;

    cout << "\nJohn Doe" << endl;
    cout << "Registrar" << endl;

    return 0;
}