#include <iostream>
using namespace std;

class X
{

    // member objects are private by default. Without declaring, members are treated to be default.

    int f; // private member

    int mf_add(int y, int z) // private and can only be accessed within a class X
    {
        int sum;
        sum = y + z;
        return sum;
    }

    // Alternatively, explicitly declare private members
    // private:
    //     int f; // private member

    //     int mf_add(int y, int z) // private and can only be accessed within a class X
    //     {
    //         int sum;
    //         sum = y + z;
    //         return sum;
    //     }

public:
    int m;    // public data member
    void mf() // Public function.

    {
        f = 5;                                                  // private object assigned a value                                             // Access private data member
        cout << "Sum of " << f << " and " << m << " is " << mf_add(f, m) << ".\n"; // Use private member function
        return;                                                 // returns nothing
    }
};

int main()
{
    X x; // class instance of class X
    // define a public function mf_add

    x.m = 10; // Assign a value to public data member, m of class x
    // x.f = 3; // return error because it is a private data member
    cout << x.m << "\n";
    x.mf(); // Use public class
}
