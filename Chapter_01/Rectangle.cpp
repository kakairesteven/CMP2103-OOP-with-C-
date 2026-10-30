#include <iostream>

class Rectangle {
private:
    // Private data members
    double width;
    double length;

public:
    // Constructor to initialize default values
    Rectangle() {
        width = 1.0;
        length = 1.0;
    }

    // Setter for width
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            std::cout << "Width must be positive!" << std::endl;
        }
    }

    // Getter for width
    double getWidth() const {
        return width;
    }

    // Setter for length
    void setLength(double l) {
        if (l > 0) {
            length = l;
        } else {
            std::cout << "Length must be positive!" << std::endl;
        }
    }

    // Getter for length
    double getLength() const {
        return length;
    }

    // Function to calculate area
    double calculateArea() const {
        return width * length;
    }

    // Function to calculate perimeter
    double calculatePerimeter() const {
        return 2 * (width + length);
    }
};

int main() {
    // 1. Create a Rectangle object
    Rectangle rect;

    std::cout << "--- Initial Default Values ---" << std::endl;
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Length: " << rect.getLength() << std::endl;

    // 2. Set new dimensions using setters
    rect.setWidth(5.5);
    rect.setLength(10.0);

    // 3. Retrieve and print dimensions using getters
    std::cout << "\n--- Updated Dimensions ---" << std::endl;
    std::cout << "New Width: " << rect.getWidth() << std::endl;
    std::cout << "New Length: " << rect.getLength() << std::endl;

    // 4. Calculate and display Area and Perimeter
    std::cout << "\n--- Calculations ---" << std::endl;
    std::cout << "Area of Rectangle: " << rect.calculateArea() << std::endl;
    std::cout << "Perimeter of Rectangle: " << rect.calculatePerimeter() << std::endl;

    return 0;
}
