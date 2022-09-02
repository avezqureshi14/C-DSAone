#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int MajorityI(vector<int>nums){
    int count = 0;
    int candidate = 0;
    for(auto i : nums){
        if (count == 0)
        {
            candidate = i;
        }
        if (i == candidate)
        {
            count++;
        }
        else{
            count--;
        }
    }    
    return candidate;
}


int main()
{
    vector<int>nums;
    nums.push_back(6);
    nums.push_back(6);
    nums.push_back(5);
    int res = MajorityI(nums);
    cout<<"Majority Element is "<<res<<endl;
    return 0;
}