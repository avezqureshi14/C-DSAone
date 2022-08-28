#include <iostream>
using namespace std;
//Prev Smaller Element
// Run twp Loops first initialized from  i = 1 and 2nd loop from j = i  , Jab apne ko jth element ith element se chota mila , then break the jth loop after printing jth element agar jth loop complete hone ke baad bhi kohi element ith element se chota nahi mila toh means (j==-1) then print -1

// Intialize:
// i = 1, j = i ;
// Traverse:
// i - from 0 to <n 
// j - from i to >=0 
void prevSmallerElement(int arr[], int n)
{
    cout << "-1 ";

    for (int i = 1; i < n; i++)
    {
        int j;
        for (j = i; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }

        if (j == -1)
        {
            cout << "-1 ";
        }
    }
}

int main()
{
    int arr[] = {4, 10, 5, 8, 20, 15, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    prevSmallerElement(arr, n);
    return 0;
}