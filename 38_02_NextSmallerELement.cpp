#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void NextSmallerElement(int arr[], int n)
{
    stack<int> s;
    for (int i = n-1; i >= 0 ; i--)
    {

        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            cout << "-1 ";
        }
        else
        {
            cout << s.top() << " ";
        }
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {3,10,5,1,15,10,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    NextSmallerElement(arr,n);

    return 0;
}