// This program outputs the message "Hello, World!" to the monitor

<<<<<<< HEAD
import std; // gain access to the C++ standard library

int main() // C++ programs start by executing the function main
{
    std::cout << "Hello, World!\n"; // output "Hello, Wor ld!"
    return 0; // Means the program executed successfully. It can be omitted.
}
=======
//import std; // gain access to the C++ standard library
//int main() // C++ programs start by executing the function main
//{
 //   std::cout << "Hello, World!\n"; // output "Hello, Wor ld!"
//    return 0; // Means the program executed successfully. It can be omitted.
//}
>>>>>>> 339890e (Mail_Merge_Assignment)








// If you don’t have an up-to-date C++ implementation that supports module std,
// use a less elegant and less efficient technique of C: a header file as


#include <iostream> // gain access to the C++ standard library

int main() // C++ programs start by executing the function main
{
    std::cout << "Hello, World!\n"; // output "Hello, Wor ld!"
    return 0;
}

