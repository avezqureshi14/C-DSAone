#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void SetZeroes(vector<vector<int>>&matrix)
{
 int rows = matrix.size(), col = matrix[0].size(), col0 = 1;
    for (int i = 0; i < rows; i++)
    {
        //agar pehli column meh ek bhi element zero hai toh poora column 0 karne ka iske liye col0 = 0 karo
        if (matrix[i][0] == 0)
        {
            col0 = 0;
        }
        
        //Dummy Matrix Creation
        //Agar konse bhi address par apne ko 0 milta toh fir apun uss row ke 0th column aur uss column ki 0th rows ko equal to karne ka 
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
            
        }
        
    }

    for (int i = rows-1; i >=0 ; i--)
    {
        for (int j = col - 1; j >= 1; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][i] == 0)
            {
                matrix[i][j] = 0;
            }
            //agar col0 = 0 hua toh pehle column ko bhi zero karo (col0 = 0, pehle column meh ek bhi zero raha toh hota)
            if (col0 == 0)
            {
                matrix[i][0] = 0;
            }
            
        }
        
    }
    
        
}
int main()
{
    
    return 0;
}