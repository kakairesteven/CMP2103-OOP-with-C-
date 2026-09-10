#include "check_soduku_solution.h"
#include <vector>

bool isValid(const vector<vector<int>> &grid);
{
    int i = 0;
    int j = 0;
    int row = 0;
    int col = 0;
    vector<vector<int>> grid;

    // Check rows
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int num = grid[i][j];
            if (grid[i][j] < 1 || grid[i][j] > 9 || not isValidAt(i, j, grid))
                return false;
        }
    }

    return true;
}

// Check whether a number is valid at a specific position in the grid
bool isValidAt(int i, int j, const vector<vector<int>> &grid)
{

    vector<vector<int>> grid;
    // Check whether grid[i][j] is valid in the i's row
    for (int j = 0; j < 9; ++j)
    {
        if (j != col && grid[row][j] == grid[row][col])
            return false;
    }

    // Check whether grid[i][j] is valid in the j's column
    for (int i = 0; i < 9; ++i)
    {
        if (i != row && grid[i][col] == grid[row][col])
            return false;
    }

    // Check whether grid[i][j] is valid in the 3x3 box
    for (int row = ((i / 3) * 3); row < ((i / 3) * 3 + 3); ++row)
    {
        for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; ++col)
        {
            if (i != row && j != col && grid[i][j] == grid[row][col])
                return false;
        }
    }

    return true;
}
