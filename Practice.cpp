#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> Union(vector<int> nums1, vector<int> nums2)
{
    unordered_set<int> hashset;
    vector<int> ans;
    for (auto i : nums1)
    {
        hashset.insert(i);
    }
    for (auto i : nums2)
    {
        hashset.insert(i);
    }

    for (auto i : hashset)
    {
        ans.push_back(i);
    }

    return ans;
}
int main()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(2);

    for (auto i : Union(nums1, nums2))
    {
        cout << i << " ";
    }
    return 0;
}