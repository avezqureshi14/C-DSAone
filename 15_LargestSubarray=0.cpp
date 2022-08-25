#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n)
{
    unordered_map <int,int> map;
    int maxi = 0;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum == 0)
        {
            maxi = i + 1;
        }
        else{

        if(map.find(curr_sum) != map.end())
        {
            maxi = max(maxi, i - map[curr_sum]);
        }
        else{
        map[curr_sum] = i;
        }
            
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"The Largest Subarray with sum equal to zero is "<<maxLen(arr,n);
    return 0;
}