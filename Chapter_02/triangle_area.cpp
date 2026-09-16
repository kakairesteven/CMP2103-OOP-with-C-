// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6
#include <iostream>
#include <cmath> 
using namespace std;

int main(){

cout<< "Enter the three points of the triangle.";

double x1, y1, x2, y2, x3, y3;

cin>> x1 >>y1 >>x2 >>y2 >>x3 >>y3; 

double side1, side2, side3, s, area;

side1 = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
side2 = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
side3 = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));

s = (side1 + side2 +side3)/2;
area = sqrt(s * (s-side1) * (s-side2) * (s-side3));

 cout<< "The area of the triangle is " <<area;

    return 0;
}
