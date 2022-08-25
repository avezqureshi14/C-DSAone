#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void insert(int arr[],int n, int value)
{
    n = n + 1;
    arr[n] = value;

    int i = n;
    while (i > 1)
    {
        int parent = i/2;
        if(arr[parent] < arr[i])
        {
            swap(arr[parent],arr[i]);

            i = parent;
        }
        else
        {
            return;
        }
    }
    
}
int main()
{
    int arr[] = {0,50,30,40,10,5,20,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr,n);
    cout<<endl;
    insert(arr,n,60);
    print(arr,n);


    return 0;
}