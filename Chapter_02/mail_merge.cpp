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
#include <ctime>
#include <iomanip>
#include <string>

    std::string getOrdinalSuffix(int day) {
    if (day >= 11 && day <= 13) return "th";
    switch (day % 10) {
        case 1:  return "st";
        case 2:  return "nd";
        case 3:  return "rd";
        default: return "th";
    }
}

using namespace std;

int main(){
    string firstName, LastName, academicyear, studyprogram;
    cout<<"Enter your first name: ";
    cin>> firstName;
    cout<<"Enter your last name: ";
    cin>> LastName;
     cout<<"Enter the academic year: ";
    cin>> academicyear;
    cout<<"Enter your study program: "; 
    //cin>> studyprogram;
    getline(cin >> ws, studyprogram); 
   cout<<"\n\n\n";
 std::time_t now = std::time(nullptr);
    std::tm* t = std::localtime(&now);

    char monthName[20];
    std::strftime(monthName, sizeof(monthName), "%B", t);

    int day = t->tm_mday;
    int year = t->tm_year + 1900;

    std::cout << "Date: " 
              << day << getOrdinalSuffix(day) << " "
              << monthName << " " 
              << year << "\n\n";


 //cout<<"Date:"<<"\n\n"<< _ _
 //cout<<"Date: "<<__DATE__<<"\n";
 cout<<"To: "<<firstName<<" "<<LastName<<"\n\n";

 cout <<"Dear "<<firstName<<","<<"\n\n";
 cout <<"CONGRATULATIONS! I am pleased to inform you that the Makerere University "<<"\n"
      <<"Admissions Board has approved your application for admission to the "<<"\n"
      <<academicyear<<" academic year.\n"
      <<"You have been offered a place for the following course:"<<"\n"
      <<"PROGRAM: "<<studyprogram<<"\n\n"
      
      <<"As a student of Makerere University, you will be part of a historic "<<"\n"
      <<"institution dedicated to academic excellence and innovation. Please ensure "<<"\n"
      <<"that you report to the Academic Registrar's office with your original "<<"\n"
      <<"academic documents for verification during the orientation week.\n\n"
      <<"We look forward to welcoming you to the Makerere University.\n\n"
      <<"Yours sincerely,\n\n\n"
      <<"John Doe\n"
      <<"Registra";




return 0;

}
