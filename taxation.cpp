#include <iostream>
using namespace std;

int main() {
    int status;
    double income, tax;

    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    cin >> status;

    cout << "Enter the taxable income: ";
    cin >> income;

    if (status == 0) {
        // Resident individual
        if (income <= 2820000) {
            tax = 0;
        }
        else if (income <= 4020000) {
            tax = (income - 2820000) * 0.10;
        }
        else if (income <= 4920000) {
            tax = (income - 4020000) * 0.20 + 120000;
        }
        else if (income <= 120000000) {
            tax = (income - 4920000) * 0.30 + 300000;
        }
        else {
            tax = (income - 4920000) * 0.30 + 300000
                  + (income - 120000000) * 0.10;
        }
    }
    else if (status == 1) {
        // Non-resident individual
        if (income <= 2820000) {
            tax = income * 0.10;
        }
        else if (income <= 4020000) {
            tax = income * 0.10;
        }
        else if (income <= 4920000) {
            tax = (income - 4020000) * 0.20 + 402000;
        }
        else if (income <= 120000000) {
            tax = (income - 4920000) * 0.30 + 582000;
        }
        else {
            tax = (income - 4920000) * 0.30 + 582000
                  + (income - 120000000) * 0.10;
        }
    }
    else {
        cout << "Invalid residence status." << endl;
        return 0;
    }

    cout << "Tax is " << tax << endl;

    return 0;
}