#include <iostream>
using namespace std;


int MaximumSubarraySum(int arr[], int n){
    int final = INT_MIN;
    int curr_max = 0;
    for (int i = 0; i < n; i++)
    {
        curr_max = curr_max + arr[i];
        if (curr_max > final)
        {
            final = curr_max;
        }
        if (curr_max < 0)
        {
            curr_max = 0;
        }

    }

    return final;
    
}


int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The Maximum Subarray sum is "<<MaximumSubarraySum(arr,n);

    return 0;
}