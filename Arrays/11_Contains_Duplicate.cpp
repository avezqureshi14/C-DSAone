#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool Contains(vector<int>nums)
{
    set<int> hashset;
    for (auto i : nums)
    {
        hashset.insert(i);
    }


    if (nums.size() == hashset.size())
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    bool res = Contains(nums);
    if (res == true)
    {
        cout<<"nahi"<<endl;
    }
    else{
        cout<<"hai"<<endl;
    }
    
    return 0;
}