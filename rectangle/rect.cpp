
#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double length;

public:
    void setDimensions(double w, double l)
    {
        width = w;
        length = l;
    }

    double getWidth()
    {
        return width;
    }

    double getLength()
    {
        return length;
    }

    double area()
    {
        return width * length;
    }

    double perimeter()
    {
        return 2 * (width + length);
    }
};

int main()
{
    Rectangle firstRectangle, secondRectangle;

    firstRectangle.setDimensions(5, 10);
    secondRectangle.setDimensions(3, 9);

    cout << "First Rectangle" << endl;
    cout << "Width = " << firstRectangle.getWidth() << endl;
    cout << "Length = " << firstRectangle.getLength() << endl;
    cout << "Area = " << firstRectangle.area() << endl;
    cout << "Perimeter = " << firstRectangle.perimeter() << endl;

    cout << "\nSecond Rectangle" << endl;
    cout << "Width = " << secondRectangle.getWidth() << endl;
    cout << "Length = " << secondRectangle.getLength() << endl;
    cout << "Area = " << secondRectangle.area() << endl;
    cout << "Perimeter = " << secondRectangle.perimeter() << endl;

    return 0;
}
