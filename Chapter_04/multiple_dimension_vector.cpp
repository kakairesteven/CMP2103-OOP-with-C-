#include <iostream>
#include <vector>
import std;
using namespace std;

int main()
{
    // Create a 2d vector containing integersv of size x by y
    int x = 0;
    int y = 0;
    int z = 0;

    // Prompt input for the number of rows and columns

    cout << "Enter number of rows: ";
    cin >> x;

    cout << "Enter number of columns: ";
    cin >> y;

    cout << "Enter the number of z-length: ";
    cin >> z;

    // Define a 3d vector of size x by y and initialize all elements to 0
    // Example v = [
    // [[0, 0, 0], [0, 0, 0]],
    // [[0, 0, 0], [0, 0, 0]]
    // ]
    vector<vector<vector<int>>> v(x, vector<vector<int>>(y, vector<int>(z, 0)));

    // Re-assign values in a 2d vector
    default_random_engine engine; // the simplest engine
    uniform_int_distribution<int> dist(0, 20);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; ++k)
            {
                v[i][j][k] = dist(engine);
            }
        }
    }

    // Unlike the 2d vector in vector.cpp, we cannot use a range-based for loop to print the 3d vector.
    // We can't display a 3d vector in terminal.
    
    // Print the value at i=4, j=6, k=3 in the 3d vector
    cout << "Value at i=4, j=6, k=3: " << v[4][6][3] << endl;   

    return 0;
}
// n-dimension arrays (vectors) are useful for representing data in multiple dimensions, such as images, videos, and scientific simulations.
// They allow for efficient storage and manipulation of data in a structured manner.
// Ref: https://docs.scipy.org/doc/scipy/tutorial/ndimage.html

// Try
// Study this program and understand its edge cases. For example, what happens if the user enters a value for x, y, or z that is less than or equal to 0?
// Implement error handling to ensure that the user inputs valid values for x, y, and z.
