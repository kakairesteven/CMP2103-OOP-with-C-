#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/* Function to get the appropriate English ordinal suffix for a given day number. */
string getDaySuffix (int day){
    if (day >= 11 && day <= 13)
    {
       return "th";
    }
     switch (day % 10){
            case 1: return "st";
            case 2: return "nd";
            case 3: return "rd";
            default: return "th";
        }
}

/* Functin to generate automatic date string. */
string getAutoDate(){
    // Get the current system time.
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    // Array of months.
    const string months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    int day = now->tm_mday;
    string month = months[now->tm_mon];
    int year = now->tm_year + 1900;
    
    // Construct formatted date.
    return to_string(day) + getDaySuffix(day) + " " + month + ", " + to_string(year);
}

int main(){
    string firstName, lastName, studyProgram, academicYear;
    
    // Obtaining the required user information.
    cout << "----- Makerere University Admission Letter Generator -----\n\n";

    cout << "Enter first name: ";
    getline(cin, firstName);

    cout << "Enter last name(s): ";
    getline(cin, lastName);

    cout << "Enter study program: ";
    getline(cin, studyProgram);

    cout << "Enter academic year: ";
    getline(cin, academicYear);

    cout << "\n\n----- GENERATED LETTER -----\n\n";
    
    //Output acceptance letter.
    cout << "Date: " << getAutoDate() << "\n\n";
    cout << "To: " << firstName << " " << lastName << ",\n\n";
    cout << "Dear " << firstName << ",\n\n";
    
    cout << "CONGRATULATIONS! I am delighted to let you know that the Makerere University\n"
         << "Amission board has approved your application for admission to the\n"
         << academicYear << " academic year.\n\n";

    cout << "We are thrilled to welcome you to the " << studyProgram << " course.\n\n";
    
    cout << "As part of Makerere University student body, you will be part of a historic\n"
         << "institution dedicated to academic excellence and innovation. Please ensure\n"
         << "that you report to the academic registrar's office with your original\n"
         << "academic documents for verification during the orientation week. \n\n";
    
    cout << "We look forward to welcoming you to Makerere University.\n\n";
    cout << "Yours sincerely,\n\n";
    cout << "John Doe,\n";
    cout << "Registrar.\n";

    return 0;
}