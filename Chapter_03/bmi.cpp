

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double weightInPounds;
    double heightInInches;

    cout << "Enter weight in pounds: ";
    cin >> weightInPounds;

    cout << "Enter height in inches: ";
    cin >> heightInInches;

    const double POUNDS_TO_KILOGRAMS = 0.45359237;
    const double INCHES_TO_METERS = 0.0254;

    double weightInKilograms = weightInPounds * POUNDS_TO_KILOGRAMS;
    double heightInMeters = heightInInches * INCHES_TO_METERS;

    double bmi = weightInKilograms / (heightInMeters * heightInMeters);

    cout << fixed << setprecision(2);
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