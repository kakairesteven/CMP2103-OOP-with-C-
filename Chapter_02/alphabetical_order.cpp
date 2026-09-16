// Rewrite the ascending.cpp program to process stings instead.
// So, if the user enters the values Electrical Eng., Computer Eng., Biomedical Eng.,
// the output should be Biomedical Eng., Computer Eng., Electrical Eng..
#include <iostream>
#include <string>
using namespace std;
int main() {
    string val1, val2, val3;
    cout << "Enter three words: ";
    getline(cin, val1);
    getline(cin, val2);
    getline(cin, val3);

    // Simple sorting logic for three values
    if (val1 > val2) {
        swap(val1, val2);
    }
    if (val2 > val3) {
        swap(val2, val3);
    }
    if (val1 > val2) {
        swap(val1, val2);
    }

    cout << val1 << ", " << val2 << ", " << val3 << endl;
    return 0;
}