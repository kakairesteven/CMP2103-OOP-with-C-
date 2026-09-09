// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6
#include<iostream>
#include<cmath>

using namespace std;
int main(){

//declaratios
//1. Coordinates
double x1, y1;
double x2, y2;
double x3, y3;

//2. Sides lengths
double Side1, Side2, Side3;

//3. final calculations
double s;
double area;

//input
cout << "Enter x1 and y1: " << endl;
cin >> x1 >> y1;
cout << "Enter x2 and y2: " << endl;
cin >> x2 >> y2;
cout << "Enter x3 and y3: " << endl;
cin >> x3 >> y3;

//calculations
//1.Side lengths
Side1 = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
Side2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
Side3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));

//2.Semi perimeter
s = (Side1 + Side2 + Side3)/2;

//3.Heron's formula for area
area = sqrt(s*(s - Side1)*(s - Side2)*(s - Side3));

//Output
//1. Side lengths
cout << "Side1 is: " << Side1 << " units" << endl;
cout << "Side2 is: " << Side2 << " units" << endl;
cout << "Side3 is: " << Side3 << " units" << endl;

//2. s and area
cout << "The value of s is: " << s << " units" << endl;
cout << "The Area of the triangle is: " << area << " square units" << endl;

return 0;
}
