#include <iostream>
using namespace std;
class Rectangle{
private:        //private data members
double width;
double length;

double getWidth() const{
    return width;
}
double getLength() const{
    return length;
}
public:
Rectangle(double w=0,double l=0){
width =w;
length =l;

}
void setWidth(double w){
    if(w>0) width =w;
}
void setLength(double l){
    if(l>0) length =l;
}
double getPerimeter() const{
    return 2*(getWidth() + getLength());
}
double getArea() const{
    return getWidth() * getLength();
}

};
int main(){
Rectangle r;

r.setWidth(5.5);
r.setLength(10.0);

cout<< "The dimensions of the rectangle 5.5 x 10.0." <<endl;
cout << "Area:"<< r.getArea() << endl;
cout << "Perimeter:"<< r.getPerimeter() << endl;

return 0;


}