#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findmaxiConsecutiveOnes(int nums[], int n)
{
    int count = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maxi = max(maxi, count);
    }
    return maxi;
}

int main()
{
    int arr[] = {1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = findmaxiConsecutiveOnes(arr,n);
    cout<<"The maximum consecutive ones is "<<res<<endl;
    return 0;
}