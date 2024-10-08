#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>>& matrix) 
    {
        std::vector<std::vector<int>> rotated;

        for (size_t col = 0; col < matrix.size(); col++)
        {
            std::vector<int> currentRow;

            for (int row = matrix.size() - 1; row >= 0; row--)
            {
                currentRow.push_back(matrix[row][col]);
            }

            rotated.push_back(currentRow);
        }

        for (size_t i = 0; i < rotated.size(); i++)
            for (size_t j = 0; j < rotated[i].size(); j++)
                matrix[i][j] = rotated[i][j];
    }
};