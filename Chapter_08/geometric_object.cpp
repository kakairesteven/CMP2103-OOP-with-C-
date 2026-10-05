// Inheritance
// PArent class
// Child classes

#include <iostream>
using namespace std;

// Geometric Object
class GeometricObject
{
private:
    string color;
    bool filled;

public:
    GeometricObject(
        string color = "green",
        bool filled = true)
        : color(color), filled(filled)
    {
    }

    string getColor() const
    {
        return color;
    }

    void setColor(const string &color)
    {
        this->color = color;
        // class(x, y):
        // this.
        // self.
    }

    bool isFilled() const
    {
        return filled;
    }

    void setFilled(bool filled)
    {
        this->filled = filled;
    }

    string toString() const
    {
        return "color: " + color +
               " and filled: " +
               (filled ? "true" : "false");
    }
};

class Circle : public GeometricObject
{
private:
    double radius;

public:
    Circle(double radius)
        : GeometricObject(), radius(radius)
    {
    }

    double getRadius() const
    {
        return radius;
    }

    // void setRadius(double radius)
    // {
    //     this->radius = radius;
    // }

    // double getArea() const
    // {
    //     return radius * radius * numbers::pi;
    // }

    // double getDiameter() const
    // {
    //     return 2 * radius;
    // }

    // double getPerimeter() const
    // {
    //     return 2 * radius * numbers::pi;
    // }

    void printCircle() const
    {
        cout << toString()
             << " radius: " << radius
             << '\n';
    }
};

int main()
{
    Circle circle(5.0);

    circle.printCircle(); // Access member function

    // std::cout << "Area: "
    //           << circle.getArea() << '\n';

    // std::cout << "Diameter: "
    //           << circle.getDiameter() << '\n';

    // std::cout << "Perimeter: "
    //           << circle.getPerimeter() << '\n';

    return 0;
}