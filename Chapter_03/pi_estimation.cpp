#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int i = 100000;
    double pi_estimation = 0;
    // int sign = 1;
    for (int i = 1; i <= 100000; ++i) {
        pi_estimation += (pow(-1, i+1) / (2 * i - 1));
        // sign = -sign;
    }

    cout << "Estimated value of pi: " << 4 * pi_estimation << endl;
}


// Try
// (Compute e) You can approximate e by using the following series:
//  e = 1 + 1/(1!) + 1/(2!) + 1/(3!) + 1/(4!) + ... + 1/(n!)
