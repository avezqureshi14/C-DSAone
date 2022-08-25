#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countDistinct(int arr[], int n)
{
    unordered_set<int>set;
    for (int i = 0; i < n; i++)
    {
       set.insert(arr[i]); 
    }
    cout<<"The number of distinct elements is "<<set.size();

    
}

int main()
{
    int arr[] = {5,8,9,4,7,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    countDistinct(arr,n);

    return 0;
}