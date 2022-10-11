#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Ques: Two Sum 
//SOrting + Two Pointers
//Sorting is needed in this method , or else we cannot be sure that element on the right are the greatest or element on the  right are smallest 
vector<int> TwoSumP2(vector<int>nums,int target){
    sort(nums.begin(),nums.end());
    // nlogn + n  or n
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
            ans.push_back(nums[left]);g
            ans.push_back(nums[right]);
            break;
        }
    }

    return ans;
    

}
int main()
{
    vector<int>nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(12);
    nums.push_back(9);
    nums.push_back(15);
    nums.push_back(13);
    nums.push_back(5);
    nums.push_back(2);

    for(int i : TwoSumP2(nums,18)){
        cout<<i<< " ";
    }

    return 0;
}