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
    vector<vector<int>>matrix;
    for (int i = 0; i < 3; i++)
    {
        vector<int>temp;
        for (int j = 0; j < 3; j++)
        {
            temp.push_back(1);
            temp.push_back(1);
            temp.push_back(1);
            temp.push_back(1);
            temp.push_back(1);
            temp.push_back(0);
            temp.push_back(1);
            temp.push_back(1);
            temp.push_back(1);
            temp.push_back(1);
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(1);
        }
        
    }
    cout<<"Before rotating"<<endl;
    for(auto i : matrix){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    rotate(matrix);

    

    return 0;
}