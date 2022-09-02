#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> TwoSumP2(vector<int>nums,int target){
    int left = 0;
    int right = nums.size() - 1;
    vector<int>ans;
    while (left <= right)
    {
        int twoSum = nums[left] + nums[right];
        if (twoSum > target)
        {
            right--;
        }
        else if(twoSum < target){
            left++;
        }
        else{
            ans.push_back(left+1);
            ans.push_back(right+1);
            break;
        }
    }

    return ans;
    

}
int main()
{
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    for(int i : TwoSumP2(nums,9)){
        cout<<i<< " ";
    }
    return 0;
}