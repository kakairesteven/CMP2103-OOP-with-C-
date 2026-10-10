/*Take-home
Design a class called Rectangle with private members width and length.
The class should have public member functions for getting and setting the width and length, 
as well as functions for calculating the area and perimeter.
In the main function, create suitable examples that demonstrate creating Rectangle objects, 
setting and retrieving their dimensions, and calculating their area and perimeter.
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    
    void setWidth(double w)
    {
        width=w;
    }

    void setLength(double l)
    {
        length=l;
    }

    double getWidth()
    {
        return width;
    }

    double getLength()
    {
        return length;
    }

    double getArea()
    {
        return width*length;
    }

    double getPerimeter()
    {
        return 2 * (width + length);
    }
};

int main() {
    Rectangle rect1;
    rect1.setWidth(5);
    rect1.setLength(10);
    cout << "Rectangle 1: " << endl;
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Length: " << rect1.getLength() << endl;
    cout << "Area: " << rect1.getArea() << endl;
    cout << "Perimeter: " << rect1.getPerimeter() << endl;

    Rectangle rect2;
    rect2.setWidth(3);
    rect2.setLength(9);
    cout << "\nRectangle 2: " << endl;
    cout << "Width: " << rect2.getWidth() << endl;
    cout << "Length: " << rect2.getLength() << endl;
    cout << "Area: " << rect2.getArea() << endl;
    cout << "Perimeter: " << rect2.getPerimeter() << endl;

    return 0;
}