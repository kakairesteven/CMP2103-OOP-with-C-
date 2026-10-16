#include <iostream>

class Rectangle {
private:
    double width;
    double length;

public:
    // Setters
    void setWidth(double w) { width = w; }
    void setLength(double l) { length = l; }

    // Getters
    double getWidth() const { return width; }
    double getLength() const { return length; }

    // Calculations
    double calculateArea() const { return width * length; }
    double calculatePerimeter() const { return 2 * (width + length); }
};

int main() {
    Rectangle rect;
    rect.setWidth(5.0);
    rect.setLength(10.0);

    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Length: " << rect.getLength() << std::endl;
    std::cout << "Area: " << rect.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect.calculatePerimeter() << std::endl;

    return 0;
}