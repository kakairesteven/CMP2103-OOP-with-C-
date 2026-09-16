// Program takes first name and last name and returns a greeting message.
#include <iostream>
#include <string>
using namespace std;

int main() // read first and second name
{
    cout << "Please enter your first and second names\n";
    string first;
    string second;
    cin >> first >> second;             // read two strings
    string name = first + ' ' + second; // concatenate strings
    cout << "Hello, " << name << '\n';

    // return 0;
}

