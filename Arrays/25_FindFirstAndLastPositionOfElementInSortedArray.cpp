#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> Binary(vector<int> &nums, vector<int> &ans, int low, int high, int target)
{

    if(low < high){
        return ans;
    }
    int mid =( low + high )/ 2;
    if (nums[mid] == target)
    {
        ans.push_back(mid);
    }
    Binary(nums, ans, low, mid - 1, target);
    Binary(nums, ans, mid + 1, high, target);
}

vector<int> Position(vector<int> &nums, int target)
{
    vector<int> ans;
    int low = 0, high = nums.size() - 1;
    Binary(nums, ans, low, high, target);

    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    for (auto i : Position(nums, 8))
    {
        cout << i << " ";
    }
    return 0;
}