#include <iostream>
using namespace std;
class Rectangle
{
private:

double length;
double width;

public:
void setWidth(double w){
    if(w > 0)
    { width = w ;}
    else{ cout << "Error. Width must be positive." << endl;}
}


void setLength(double len){
    if(len > 0)
    { 
        length = len;}
    else { cout << "Error. Legth must be positive." << endl;}
}

double getWidth(){ return width;}
double getLength(){ return length;}
double calculateArea(){ return width*length;}
double calculatePerimeter(){ return 2* (width + length);}
};
int main (){

Rectangle rect1;
rect1.setWidth(5.5);
rect1.setLength( 10.0);
cout << "Width:" <<rect1.getWidth()<<endl;
cout<< "Length:" <<rect1.getLength() <<endl;

cout << "Area:" <<rect1.calculateArea() <<endl;
cout <<"Perimeter:" <<rect1.calculatePerimeter() <<endl;

    return 0;

}