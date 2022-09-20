#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>nums){
    int currSum = 0;
    int totalSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        currSum = currSum + nums[i];
        if (currSum > totalSum)
        {
            totalSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
        totalSum = max(totalSum,currSum);        
    }

    return totalSum;
    
}
int main()
{
    vector<int>nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout<<"Sum is "<<subarraySum(nums);
    return 0;
}