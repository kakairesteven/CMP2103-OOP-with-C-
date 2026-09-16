#include "check_soduku_solution.h"
#include <vector>

bool isValidAt(int row, int col, const std::vector<std::vector<int>>& grid)
{
    int value = grid[row][col];
    if (value < 1 || value > 9)
        return false;

    // Check the row.
    for (int c = 0; c < 9; ++c)
    {
        if (c != col && grid[row][c] == value)
            return false;
    }

    // Check the column.
    for (int r = 0; r < 9; ++r)
    {
        if (r != row && grid[r][col] == value)
            return false;
    }

    // Check the 3x3 box.
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = startRow; r < startRow + 3; ++r)
    {
        for (int c = startCol; c < startCol + 3; ++c)
        {
            if ((r != row || c != col) && grid[r][c] == value)
                return false;
        }
    }

    return true;
}

bool isValid(const std::vector<std::vector<int>>& grid)
{
    if (grid.size() != 9)
        return false;

    for (const auto& row : grid)
    {
        if (row.size() != 9)
            return false;
    }

    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            if (!isValidAt(r, c, grid))
                return false;
        }
    }

    return true;
}
