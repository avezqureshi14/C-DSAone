#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int>&nums, int k){
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end()); //dont consider the begin + k element here
}
void print(vector<int>&nums){
    for(int i : nums){
        cout<<i<<" ";
    }
}

int main()
{
    vector<int>nums;
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
 
    rotate(nums,32);
    print(nums);
    return 0;
}