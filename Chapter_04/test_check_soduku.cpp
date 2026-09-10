#include <iostream>
#include <vector>
#include "check_soduku_solution.h"

using namespace std;

vector<vector<int>> readAsolution()
{
    cout << "Enter the Sudoku solution (9x9 grid):" << endl;

    vector<vector<int>> grid;

    for (int i = 0; i < 9; ++i)
    {
        vector<int> row(9);

        for (int j = 0; j < 9; ++j)
        {
            cin >> row[j];
        }

        grid.push_back(row);
    }

    return grid;
}

int main()
{
    vector<vector<int>> grid = readAsolution();

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