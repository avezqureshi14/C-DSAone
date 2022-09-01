#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int rows = matrix.size();

    //finding transpose
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //reverse
    for (int i = 0; i < rows; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{

    return 0;
}