#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

double calculateTax(int status, double cy) {
    double tax = 0.0;

    if (status == 0) {  // Resident
        if (cy <= 2820000) {
            tax = 0.0;
        } else if (cy <= 4020000) {
            tax = (cy - 2820000) * 0.10;
        } else if (cy <= 4920000) {
            tax = (cy - 4020000) * 0.20 + 120000;
        } else if (cy <= 120000000) {
            tax = (cy - 4920000) * 0.30 + 300000;
        } else {
            tax = ((cy - 4920000) * 0.30 + 300000) + ((cy - 120000000) * 0.10);
        }
    } else if (status == 1) {  // Non-Resident
        if (cy <= 2820000) {
            tax = cy * 0.10;
        } else if (cy <= 4020000) {
            tax = cy * 0.10;
        } else if (cy <= 4920000) {
            tax = (cy - 4020000) * 0.20 + 402000;
        } else if (cy <= 120000000) {
            tax = (cy - 4920000) * 0.30 + 582000;
        } else {
            tax = ((cy - 4920000) * 0.30 + 582000) + ((cy - 120000000) * 0.10);
        }
    }

    return tax;
}

int main() {
    int status;
    string incomeStr;

    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    cin >> status;

    cout << "Enter the taxable income: ";
    cin >> incomeStr;

    // Remove commas from the input string if any
    incomeStr.erase(remove(incomeStr.begin(), incomeStr.end(), ','), incomeStr.end());
    
    double income = stod(incomeStr);
    double tax = calculateTax(status, income);

    cout << fixed << setprecision(0) << "Tax is " << tax << endl;

    return 0;
}