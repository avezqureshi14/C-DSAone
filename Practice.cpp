#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> TwoSum(vector<int> nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            ans.push_back(map[target - nums[i]]);
            ans.push_back(i);
        }
        map[nums[i]] = i;
    }

    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(12);
    nums.push_back(9);
    nums.push_back(15);
    nums.push_back(13);
    nums.push_back(5);
    nums.push_back(2);

    vector<int>res = TwoSum(nums,7);
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}