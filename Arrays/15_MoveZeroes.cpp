#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Remember we don't have to change the order of the non zero element , i.e we cannot sort the array
void MoveZeroes(vector<int>&nums){
    int nonZero = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j] , nums[nonZero]);
            nonZero++;
        }
        
    }
    
}

void print(vector<int>nums){
    for(int i:nums){
        cout<<i<< " ";
    }
}
int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    MoveZeroes(nums);
    print(nums);
    return 0;
}