#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//ANY TWO NUMBERS WHOSE SUM IS EQUAL TO THE GIVEN TARGET, i MIGHT NOT BE IN SEQUENCE 
vector<int> TwoSum(vector<int> &nums, int sum)
{
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(sum - nums[i]) != map.end())
        {
            ans.push_back(map[sum - nums[i]]);
            ans.push_back(i);
            return ans;
        }

        map[nums[i]] = i;
    }
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    vector<int> res = TwoSum(nums, 6);
    for (int i : res)
    {
        cout << i;
    }

    return 0;
}