#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int LongestStreak(vector<int>nums){
    set<int>hashset;
    for(int i : nums){
        hashset.insert(nums[i]);
    }

    for(int i : nums){
        while (!hashset.count(i-1))
        {
            int curr = i;
            int curr_seq = 1;
            
        }
        
    }
    
}
int main()
{
    
    return 0;
}