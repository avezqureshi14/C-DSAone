#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        //agar pehli column meh ek bhi element zero hai toh poora column 0 karne ka iske liye col0 = 0 karo

        if (matrix[i][0] == 0)
        {
            col0 = 0;
        }
        //Dummy Matrix Creation
        //Agar konse bhi address par apne ko 0 milta toh fir apun uss row ke 0th column aur uss column ki 0th rows ko equal to karne ka 

        for (int j = 0; j < cols; j++)
        {
            // agar kohi sa element zero milra toh uske corresponding pehla column aur row zero karo
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for (int i = rows-1; i >= 0; i++)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                //agar pehle row ya firr pehle column meh ek bhi element zero hai to uske corresponding saare rows aur column zero karo
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
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
}

int main()
{

    return 0;
}