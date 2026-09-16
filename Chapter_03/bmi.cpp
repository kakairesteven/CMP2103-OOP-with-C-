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
using namespace std;

int main() {
    const double POUND_TO_KG = 0.45359237;
    const double INCH_TO_M = 0.0254;

    double weightInPounds;
    double heightInInches;

    cout << "Enter weight in pounds: ";
    cin >> weightInPounds;

    cout << "Enter height in inches: ";
    cin >> heightInInches;

    double weightInKg = weightInPounds * POUND_TO_KG;
    double heightInMeters = heightInInches * INCH_TO_M;
    double bmi = weightInKg / (heightInMeters * heightInMeters);

    cout << "BMI is " << bmi << endl;

    if (bmi < 18.5)
        cout << "Underweight" << endl;
    else if (bmi < 25.0)
        cout << "Normal" << endl;
    else if (bmi < 30.0)
        cout << "Overweight" << endl;
    else
        cout << "Obese" << endl;

    return 0;
}