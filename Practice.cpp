#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> InterSection(vector<int>nums1,vector<int>nums2){
    vector<int>ans;
    unordered_map<int,int>map;
    for (int i = 0; i < nums1.size(); i++)
    {
        map[nums1[i]] = i;
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        auto itr = map.find(nums2[i]);
        if(map.end() != itr )
    }
    
    
    
    return ans;
    
}

int main()
{
    vector<int>nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);
    
    vector<int>nums2;
    nums2.push_back(2);
    nums2.push_back(2);

    for(int i : InterSection(nums1,nums2))
    {
        cout<<i<<" ";
    }
    return 0;
}