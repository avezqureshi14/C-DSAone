#include <iostream>
using namespace std;

int findWater(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    int left_max = 0;
    int right_max = 0;
    int water = 0;

    while (low <= high)
    {
        if (arr[low] <= arr[high])
        {
            if (arr[low] > left_max)
            {
                left_max = arr[low];
            }
            else
            {
                water += left_max - arr[low];
            }
            low++;
       }
        else
        {
            if (arr[high] > right_max)
            {
                right_max = arr[high];
            }
            else
            {
                water += right_max - arr[high];
            }
            high--;
        }

    }

    return water;
}

int main()
{
    int arr[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = findWater(arr,n);
    cout<<"The maximum water which can be filled is "<<res<<endl;
    return 0;
}