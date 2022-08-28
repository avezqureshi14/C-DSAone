#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prevSmaller(int arr[], int n)
{
    stack<int>s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= arr[i]) //for prev greater element just change here the sign.
        {
            s.pop();
        }
        if(s.empty())
        {
            cout<<"-1 ";
        }
        else{
            cout<<s.top()<<" ";
        }

        s.push(arr[i]);
        
    }
}

int main()
{
    int arr[] = {4,10,5,8,20,15,3,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    prevSmaller(arr,n);
    return 0;
}

//Time Complexity is O(n)