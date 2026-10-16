
#include <iostream>
#include <iomanip>

int main() {
    int residenceStatus;
    double chargeableIncome;
    double tax = 0.0;

    // 1. Prompt the user for input parameters exactly as requested
    std::cout << "(0-Resident, 1-Non-resident)" << std::endl;
    std::cout << "Enter the residence status: ";
    std::cin >> residenceStatus;

    std::cout << "Enter the taxable income: ";
    std::cin >> chargeableIncome;

    // 2. Perform computing logic based on status and tax brackets
    if (residenceStatus == 0) {
        // RESIDENT TAX BRACKETS
        if (chargeableIncome <= 2820000) {
            tax = 0.0;
        } else if (chargeableIncome <= 4020000) {
            tax = (chargeableIncome - 2820000) * 0.10;
        } else if (chargeableIncome <= 4920000) {
            tax = ((chargeableIncome - 4020000) * 0.20) + 120000;
        } else {
            // Covers income up to and above 120,000,000
            tax = ((chargeableIncome - 4920000) * 0.30) + 300000;
        }

        // Additional 10% surtax for income above 120,000,000
        if (chargeableIncome > 120000000) {
            tax += (chargeableIncome - 120000000) * 0.10;
        }

    } else if (residenceStatus == 1) {
        // NON-RESIDENT TAX BRACKETS
        if (chargeableIncome <= 4020000) {
            tax = chargeableIncome * 0.10;
        } else if (chargeableIncome <= 4920000) {
            tax = ((chargeableIncome - 4020000) * 0.20) + 402000;
        } else {
            // Covers income up to and above 120,000,000
            tax = ((chargeableIncome - 4920000) * 0.30) + 582000;
        }

        // Additional 10% surtax for income above 120,000,000
        if (chargeableIncome > 120000000) {
            tax += (chargeableIncome - 120000000) * 0.10;
        }
    } else {
        std::cout << "Invalid status entered." << std::endl;
        return 1;
    }

    // 3. Output the exact calculated metric
    std::cout << "Tax is " << std::fixed << std::setprecision(0) << tax << "." << std::endl;

    return 0;
}