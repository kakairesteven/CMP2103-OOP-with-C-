// A program that generates and prints a matrix of size x by y.

#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main()
{
    int number_of_rows = 0;
    int number_of_columns = 0;

    // Read in the number of rows and columns
    cout << "Enter number of rows: " << "\n";
    cin >> number_of_rows;

    cout << "Enter number of columns: " << "\n";
    cin >> number_of_columns;

    // Define matrix
    // v1 = [
    // [8, 7, 87, 4],
    // [67, 8, 5, 4]
    // ]
    // i == row, 0
    // j == column, 3
    // v1[0][3] = 4
    vector<vector<int>> v1(number_of_rows, vector<int>(number_of_columns, 0));

    // Random number generator
    random_device rd;                      // non-deterministic generator
    mt19937 gen(rd());                     // to seed mersenne twister. Mersene twister is a pseudo random number generator
    uniform_int_distribution<> dist(0, 9); // Define a distribution

    // Print matrix
    for (int i = 0; i < number_of_rows; ++i)
    {
        for (int j = 0; j < number_of_columns; ++j)
        {

            // Reassign values in a matrix
            v1[i][j] = dist(gen);
            std::cout << v1[i][j] << ' ';
        }

        std::cout << '\n';
    }

    return 0;
}
