// A program that prompts for a first name and return a greeting.
<<<<<<< HEAD
import std;
// using namespace std;
=======
//#include "PPPheaders.h"
//import std;
//using namespace std;
#include <iostream>
>>>>>>> 339890e (Mail_Merge_Assignment)

int main()
{
    std::cout << "Please enter your first name (followed by 'enter'):\n";
    std::string first_name; // first_name is a variable of type string
    std::cin >> first_name; // read characters into first_name
    std::cout << "Hello, " << first_name << "!\n";

    return 0;
}