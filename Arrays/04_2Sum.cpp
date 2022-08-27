#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>TwoSum(vector<int>nums,int target){
    unordered_map<int,int>map;
    vector<int>ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(target-nums[i]) != map.end())
        {
            ans.push_back(map[target-nums[i]]);
            ans.push_back(i);
        }
        map[nums[i]]=i;
        
    }
    return ans;
    
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    vector<int>res = TwoSum(nums,6);
    for(auto i : res){
        cout<<i<<" ";
    }

    return 0;
}