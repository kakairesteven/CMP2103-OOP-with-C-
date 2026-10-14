// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5–24.9 Normal
// 25.0–29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter Weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal

#include <iostream>
#include <iomanip> // For formatting output to 2 decimal places

int main() {
    // Constants for conversion rates
    const double KILOGRAMS_PER_POUND = 0.45359237;
    const double METERS_PER_INCH = 0.0254;

    double weightInPounds = 0.0;
    double heightInInches = 0.0;

    // Prompt the user for input
    std::cout << "Enter weight in pounds: ";
    std::cin >> weightInPounds;

    std::cout << "Enter height in inches: ";
    std::cin >> heightInInches;

    // Convert to metric units
    double weightInKilograms = weightInPounds * KILOGRAMS_PER_POUND;
    double heightInMeters = heightInInches * METERS_PER_INCH;

    // Calculating the  BMI
    double bmi = weightInKilograms / (heightInMeters * heightInMeters);

    // Display the BMI rounded to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "BMI is " << bmi << std::endl;

    // display of interpretation based on conditions
    if (bmi < 18.5) {
        std::cout << "Underweight" << std::endl;
    } 
    else if (bmi < 25.0) {
        std::cout << "Normal" << std::endl;
    } 
    else if (bmi < 30.0) {
        std::cout << "Overweight" << std::endl;
    } 
    else {
        std::cout << "Obese" << std::endl;
    }

    return 0;
}