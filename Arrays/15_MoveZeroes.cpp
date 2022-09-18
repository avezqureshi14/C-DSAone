#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Remember we don't have to change the order of the non zero element , i.e we cannot sort the array
//Agar zero dikha toh ignore karo nahi toh swap karo 
void MoveZeroes(vector<int>&nums){
    int nonZero = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i] , nums[nonZero]);
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