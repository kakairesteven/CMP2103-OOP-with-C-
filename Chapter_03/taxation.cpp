#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int residenceStatus;
    double taxableIncome;
    double tax = 0.0;

    // Display status choices and get user input
    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    cin >> residenceStatus;

    cout << "Enter the taxable income: ";
    cin >> taxableIncome;

    // Calculate tax based on residency status
    if (residenceStatus == 0) { 
        // Resident brackets
        if (taxableIncome <= 2820000) {
            tax = 0.0;
        } else if (taxableIncome <= 4020000) {
            tax = (taxableIncome - 2820000) * 0.10;
        } else if (taxableIncome <= 4920000) {
            tax = (taxableIncome - 4020000) * 0.20 + 120000;
        } else if (taxableIncome <= 120000000) {
            tax = (taxableIncome - 4920000) * 0.30 + 300000;
        } else {
            // Over 120,000,000 (Includes the additional 10% super tax)
            tax = ((taxableIncome - 4920000) * 0.30 + 300000) + ((taxableIncome - 120000000) * 0.10);
        }
    } else if (residenceStatus == 1) { 
        // Non-resident brackets
        if (taxableIncome <= 4020000) {
            tax = taxableIncome * 0.10;
        } else if (taxableIncome <= 4920000) {
            tax = (taxableIncome - 4020000) * 0.20 + 402000;
        } else if (taxableIncome <= 120000000) {
            tax = (taxableIncome - 4920000) * 0.30 + 582000;
        } else {
            // Over 120,000,000 
            tax = ((taxableIncome - 4920000) * 0.30 + 582000) + ((taxableIncome - 120000000) * 0.10);
        }
    } else {
        cout << "Invalid residence status!" << endl;
        return 1;
    }

    // Output the calculated tax matching the required format
    cout << "Tax is " << fixed << setprecision(0) << tax << "." << endl;

    return 0;
}
