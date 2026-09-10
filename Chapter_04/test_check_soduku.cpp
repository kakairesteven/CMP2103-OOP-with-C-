// A program that reads a soduku solution from a file and determines if it is right or not.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Function declarations
bool isValidAt(int i, int j, vector<vector<int>> grid);
bool isValid(vector<vector<int>> grid);
vector<vector<int>> readASolution();

// Check whether the entire Sudoku solution is valid
bool isValid(vector<vector<int>> grid)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int num = grid[i][j];

            if (num < 1 || num > 9)
            {
                return false;
            }

            if (!isValidAt(i, j, grid))
            {
                return false;
            }
        }
    }

    return true;
}

// Check whether grid[i][j] is valid in the grid
bool isValidAt(int i, int j, vector<vector<int>> grid)
{

    // Check whether grid[i][j] is valid in i's row
    for (int col = 0; col < 9; ++col)
    {
        if (col != j && grid[i][col] == grid[i][j])
        {
            return false;
        }
    }

    // Check whether grid[i][j] is valid in j's column
    for (int row = 0; row < 9; ++row)
    {
        if (row != i && grid[row][j] == grid[i][j])
        {
            return false;
        }
    }

    // Check whether grid[i][j] is valid in the 3-by-3 box
    for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; ++row)
    {
        for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; ++col)
        {
            if ((row != i && col != j) && grid[row][col] == grid[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

// Read Sudoku solution
vector<vector<int>> readASolution()
{
    ifstream file("sudoku.txt");

    if (!file)
    {
        cerr << "Could not open sudoku.txt" << endl;
        return {};
    }

    vector<vector<int>> grid(9, vector<int>(9));

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (!(file >> grid[i][j]))
            {
                cerr << "Invalid Sudoku file." << endl;
                return {};
            }
        }
    }

    return grid;
}

int main()
{
    vector<vector<int>> grid = readASolution();
    //     vector<vector<int>> grid = {
    //     {5, 3, 4, 6, 7, 8, 9, 1, 2},
    //     {6, 7, 2, 1, 9, 5, 3, 4, 8},
    //     {1, 9, 8, 3, 4, 2, 5, 6, 7},
    //     {8, 5, 9, 7, 6, 1, 4, 2, 3},
    //     {4, 2, 6, 8, 5, 3, 7, 9, 1},
    //     {7, 1, 3, 9, 2, 4, 8, 5, 6},
    //     {9, 6, 1, 5, 3, 7, 2, 8, 4},
    //     {2, 8, 7, 4, 1, 9, 6, 3, 5},
    //     {3, 4, 5, 2, 8, 6, 1, 7, 9}
    // };

    if (isValid(grid))
    {
        cout << "The Sudoku solution is valid." << endl;
    }
    else
    {
        cout << "The Sudoku solution is not valid." << endl;
    }

    return 0;
}