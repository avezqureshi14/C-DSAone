#include <iostream>
using namespace std;
//Next Smaller Element
// Run twp Loops first initialized from  i = 0 and 2nd loop from j = i +1  , Jab apne ko jth element ith element se chota mila , then break the jth loop after printing jth element agar jth loop complete hone ke baad bhi kohi element ith element se chota nahi mila toh means (j==-1) then print -1

// Intialize:
// i = 0, j = i + 1;
// Traverse:
// i - from 0 to <n 
// j = from i + 1 to <n 

void nextSmallerElement(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }

        if (j == n)
        {
            cout << -1 << " ";
        }
    }
}

int main()
{
    int arr[] = {3, 10, 5, 1, 15, 10, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextSmallerElement(arr, n);
    return 0;
}

// Time Complexity is O(n^2)