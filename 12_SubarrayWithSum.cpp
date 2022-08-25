#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// SEQUENCE OF NUMBERS GIVING THE SUM SAME AS THE GIVEN SUM 
//Here we use this following Formula
//if(curr_sum == sum)
    //then you got your indices from 0 to curr_sumIndex
//elseif ((curr_sum - sum) = Hash Value )
    //then you got your indices from HashValueIndex + 1 to curr_sumIndex
//else curr_sum -> curr_sumIndex (Put inside Hash Table)

void SubArraySum(int arr[], int n, int sum)
{

    //Creating an Empty Map
    unordered_map <int,int> map;

    //Maintain sum of ELements
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];

        if(curr_sum == sum)
        {
            cout<<"Sum of Indexes found between 0 and "<<i;
        }
        if(map.find(curr_sum - sum) != map.end() ) 
        {
            cout<<"Sum found between indexes "
                <<map[curr_sum - sum] + 1 
                <<" and "<<i<<endl;
            return;
        }

        map[curr_sum] = i;
    }

    //If reached here, then no subarray exists
    cout<<"No subarray of the given sum exists"<<endl;
}

int main()
{
    int arr[] = {15,2,4,8,9,5,10,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    SubArraySum(arr,n,23);
    return 0;
}

// Time Complexity O(nlogn)
// Space Complexity O(n)