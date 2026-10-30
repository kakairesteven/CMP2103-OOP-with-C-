#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    void setWidth(double w) {
        width = w;
    }

    void setLength(double l) {
        length = l;
    }

    double getWidth() {
        return width;
    }

    double getLength() {
        return length;
    }

    double getArea() {
        return width * length;
    }

    double getPerimeter() {
        return 2 * (width + length);
    }
};

int main() {
    Rectangle rectangle1;

    rectangle1.setWidth(5.5);
    rectangle1.setLength(10.0);

    cout << "Rectangle 1" << endl;
    cout << "Width: " << rectangle1.getWidth() << endl;
    cout << "Length: " << rectangle1.getLength() << endl;
    cout << "Area: " << rectangle1.getArea() << endl;
    cout << "Perimeter: " << rectangle1.getPerimeter() << endl;

    Rectangle rectangle2;

    rectangle2.setWidth(4.0);
    rectangle2.setLength(6.0);

    cout << "\nRectangle 2" << endl;
    cout << "Width: " << rectangle2.getWidth() << endl;
    cout << "Length: " << rectangle2.getLength() << endl;
    cout << "Area: " << rectangle2.getArea() << endl;
    cout << "Perimeter: " << rectangle2.getPerimeter() << endl;

    return 0;
}