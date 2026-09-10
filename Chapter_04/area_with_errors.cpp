import std;
using namespace std;

// class Bad_area{

// };

// int area (int length, int width)
// {
//     if (length <= 0 || width <= 0)
//         throw Bad_area();
//     return length * width;
// }

// void test(int x, int y, int z)
// {
//     int area1 = area(x, y);
//     int area2 = area(y, z);

//     double ratio = area1 / area2;
// }

// int main()
// try {
//     test(-3, 3, 4);
// }
// catch (Bad_area) {
//     std::cout << "Oops! bad argument to area()\n";
// }

int main()
try
{
    // our program
    int x = 0;
    int y = 5;
    
    int z = y / x; // division by zero
    return 0;      // 0 indicates success
}
catch (exception& e)
{
    cerr << "error: " << e.what() << '\n';
    return 1; // 1 indicates failure
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    return 2; // 2 indicates failure
}