#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
    {
        return false;
    }

    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = (n * m) - 1;

    while (low <= high)
    {
        int mid = (low + (high - low)) / 2;
        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        if (matrix[mid / m][mid % m] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
        if (target >= matrix[i][0])
            if (binary_search(matrix[i].begin(), matrix[i].end(), target))
                return true;
    return false;
}

int main()
{

    return 0;
}