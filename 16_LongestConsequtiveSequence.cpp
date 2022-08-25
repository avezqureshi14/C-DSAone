#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int LongestSequence(vector<int>&nums)
{
    set<int> hashset;
    for (int i : nums)
    {
        hashset.insert(i);
    }

    int longestStreak = 0;

    for (int i : nums)
    {
        if (!hashset.count(i - 1)) // i is not the index it is number itself from the vector
        {
            int curr_num = i;
            int curr_seq_len = 1;
            while (hashset.count(curr_num + 1))
            {
                curr_num++;
                curr_seq_len++;
            }

            longestStreak = max(longestStreak, curr_seq_len);
        }
    }
    return longestStreak;
}

int main()
{

    vector<int> nums;
    nums.push_back(102);
    nums.push_back(4);
    nums.push_back(100);
    nums.push_back(1);
    nums.push_back(101);
    nums.push_back(3);
    nums.push_back(2);

    cout << "The Longest Sequence is of Length " << LongestSequence(nums);

    return 0;
}

//Time Complexity is O(3n)
//Space Complexity is O(n)