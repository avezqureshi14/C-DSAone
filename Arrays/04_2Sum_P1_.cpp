#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//just go on checking that target - curr element is present inside our map, if it is not present than just add it 

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
        map[nums[i]]=i; //this is not the else condition you have to insert inside the set even if it is inserted before(duplicates are allowed)
        
    }
    return ans;
    
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    vector<int>res = TwoSum(nums,6);
    for(auto i : res){
        cout<<i<<" ";
    }

    return 0;
}