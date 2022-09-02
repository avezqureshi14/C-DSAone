#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> nums1, vector<int> nums2)
{
    unordered_map<int, int> m;
        
        for(int i = 0; i < nums1.size(); ++i)
        {
            m[nums1[i]] += 1;
        }
        
        vector<int> retVal;
        for(int i = 0; i < nums2.size(); ++i)
        {
            auto it = m.find(nums2[i]);
            if(m.end() != it && it->second > 0)
            {
                retVal.push_back(nums2[i]);
                it->second -= 1;
            }
        }
        
        return retVal;
}

int main()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(1);

    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(2);

    for (auto i : Intersection(nums1, nums2))
    {
        cout << i << " ";
    }

    return 0;
}