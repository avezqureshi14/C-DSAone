#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Bactracking is involved in the question
void Permutation(vector<int>nums,vector<vector<int>>&ans, int index){
    //base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        Permutation(nums,ans,index+1);
        //backtrack
        swap(nums[index],nums[j]);
    }
    
    
}

vector<vector<int>>Permutation(vector<int>&nums){
    vector<vector<int>>ans;
    int index = 0;
    Permutation(nums,ans,index);
    return ans;
}

int main()
{
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(4);
    for(vector<int> i : Permutation(nums)){
        for(int j : i){
            cout<<j;
        }
        cout<<" ";
    }
    return 0;
}