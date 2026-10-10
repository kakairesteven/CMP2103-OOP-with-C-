#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    void setwidth(double w){
        width=w;
    }
    void setlength(double l){
        length=l;
    }
    double getwidth(){
        return width;
    }
    double getlength(){
        return length;
    }
    double calculatearea(){
        return width*length;
    }
    double calculateperimeter(){
        return 2 * (width + length);
    }
};

int main() {
    Rectangle rectangle1;
    rectangle1.setwidth(6);
    rectangle1.setlength(14);
    cout << "Rectangle 1: " << endl;
    cout << "Width is: " << rectangle1.getwidth() << endl;
    cout << "Length is: " << rectangle1.getlength() << endl;
    cout << "Area is: " << rectangle1.calculatearea() << endl;
    cout << "Perimeter is: " << rectangle1.calculateperimeter() << endl;

    Rectangle rectangle2;
    rectangle2.setwidth(7);
    rectangle2.setlength(11);
    cout << "\nRectangle 2: " << endl;
    cout << "Width is: " << rectangle2.getwidth() << endl;
    cout << "Length is: " << rectangle2.getlength() << endl;
    cout << "Area is: " << rectangle2.calculatearea() << endl;
    cout << "Perimeter is: " << rectangle2.calculateperimeter() << endl;

    return 0;
}