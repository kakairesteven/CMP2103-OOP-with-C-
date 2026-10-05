#include <iostream>
using namespace std;

// pass-by-value (give the function a copy of the value passed)
int f(int x)
{
    x = x + 1; // give the local x a new value
    return x;
}

int main()
{
    int xx = 0;
    cout << f(xx) << '\n'; // write: 1
    cout << xx << '\n';    // write: 0; f() doesn’t change xx
    int yy = 7;
    cout << f(yy) << '\n'; // write: 8
    cout << yy << '\n';    // write: 7; f() doesn’t change yy
}
