#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    // Create a 3d vector containing integers of size x by y by z
    int x = 0;
    int y = 0;
    int z = 0;

    // Prompt input for the number of rows, columns, and z-depth.
    while (true)
    {
        cout << "Enter number of rows (must be > 0): ";
        cin >> x;

        if (x > 0)
            break;

        cout << "Invalid input. Rows must be greater than 0." << endl;
    }

    while (true)
    {
        cout << "Enter number of columns (must be > 0): ";
        cin >> y;

        if (y > 0)
            break;

        cout << "Invalid input. Columns must be greater than 0." << endl;
    }

    while (true)
    {
        cout << "Enter the number of z-length (must be > 0): ";
        cin >> z;

        if (z > 0)
            break;

        cout << "Invalid input. Z-length must be greater than 0." << endl;
    }

    // Define a 3d vector of size x by y by z and initialize all elements to 0
    vector<vector<vector<int>>> v(x, vector<vector<int>>(y, vector<int>(z, 0)));

    // Re-assign values in the 3d vector
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

    // Print the value at i=4, j=6, k=3 in the 3d vector if it exists.
    if (x > 4 && y > 6 && z > 3)
    {
        cout << "Value at i=4, j=6, k=3: " << v[4][6][3] << endl;
    }
    else
    {
        cout << "The requested index (4, 6, 3) is out of range for a "
             << x << " x " << y << " x " << z << " vector." << endl;
    }

    return 0;
}
// n-dimension arrays (vectors) are useful for representing data in multiple dimensions, such as images, videos, and scientific simulations.
// They allow for efficient storage and manipulation of data in a structured manner.
// Ref: https://docs.scipy.org/doc/scipy/tutorial/ndimage.html

// Try
// Study this program and understand its edge cases. For example, what happens if the user enters a value for x, y, or z that is less than or equal to 0?
// Implement error handling to ensure that the user inputs valid values for x, y, and z.
