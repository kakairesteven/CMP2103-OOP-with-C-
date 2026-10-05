#include <iostream>
#include <iomanip>

int main() {
    // Conversion constants
    const double KILOGRAMS_PER_POUND = 0.45359237;
    const double METERS_PER_INCH = 0.0254;

    double weightInPounds, heightInInches;

    // Prompt user for input
    std::cout << "Enter weight in pounds: ";
    std::cin >> weightInPounds;

    std::cout << "Enter height in inches: ";
    std::cin >> heightInInches;

    // Convert inputs to metric system
    double weightInKilograms = weightInPounds * KILOGRAMS_PER_POUND;
    double heightInMeters = heightInInches * METERS_PER_INCH;

    // Calculate BMI: weight (kg) / (height (m))^2
    double bmi = weightInKilograms / (heightInMeters * heightInMeters);

    // Display formatted BMI result
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "BMI is " << bmi << "\n";

    // Interpret BMI status based on specified thresholds
    if (bmi < 18.5) {
        std::cout << "Underweight\n";
    } else if (bmi < 25.0) {
        std::cout << "Normal\n";
    } else if (bmi < 30.0) {
        std::cout << "Overweight\n";
    } else {
        std::cout << "Obese\n";
    }

    return 0;
}