#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity is O(nlogn) and Space Complexity is O(1)
// Note: This Solution is better for finding any number of  Duplicate number 

void Brute_Duplicates(int arr[], int n){
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << "Duplicates are " << arr[i] << endl;
        }
    }
}

// Time Complexity is O(n) and Space Complexity O(1)
// Note: This Solution is better for finding only one Duplicate number 

//Assign two pointers slow and fast intialize slow and fast from arr[0]
//Run two loops 
//Loop 1 do...while loop : slow will walk one step and fast twicw of slow
//Loop 2 while loop : both of them walks one step and return slow
// run both the loops till slow != fast
int Optimal_Duplicates(int arr[], int n){
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
    
    
}





void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 4, 8, 5, 1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Duplicates element is "<<Optimal_Duplicates(arr,n);
    return 0;
}