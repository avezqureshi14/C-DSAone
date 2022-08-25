#include <iostream>
using namespace std;
//Doh varibable banao final_sum aur current_sum, Initialize final_sum = INT_MIN and current_sum = 0, Array ke each element ko current_sum meh add karo, agar current_sum > final_sum toh final_sum = current_sum aur uske saath agar current_sum < 0, then current_sum = 0, return final
int maximumSubarraySum(int arr[], int n)
{
    int final = INT_MIN;
    int current_max = 0;
    for (int i = 0; i < n; i++)
    {
        current_max = current_max + arr[i];
        if (current_max > final)
        {
            final = current_max;
        }
        if (current_max < 0)
        {
            current_max = 0;
        }
    }
    return final;
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"The Maximum Sum Subarray is "<<maximumSubarraySum(arr,n);

    return 0;
}