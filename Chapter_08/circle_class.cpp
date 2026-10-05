#include <iostream>
//removed the header file <numbers> because my computer coundn't read it 
constexpr double pi = 3.142; //rounded off the value of pi to 3 decimal places
using namespace std;

class Circle
{
private:
    double radius;

public:
    // Construct a circle object
    Circle(double radius = 1)
        : radius{radius}
    {
    }

    double getPerimeter()
    {
        return 2 * radius * pi;
    }

    double getArea()
    {
        return radius * radius * pi;
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }
};

int main()
{
    Circle circle(5);

    std::cout << "Area: " << circle.getArea() << '\n';
    std::cout << "Perimeter: " << circle.getPerimeter() << '\n';

    circle.setRadius(10);

    std::cout << "New area: " << circle.getArea() << '\n';
    std::cout << "New perimeter: " << circle.getPerimeter() << '\n';

    return 0;
}