#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int LongestStreak(vector<int> nums)
{
    set<int> hashset;
    for (int i : nums)
    {
        hashset.insert(nums[i]);
    }

    for (int i : nums)
    {

        int longestStreak = 0;
        while (!hashset.count(i - 1))
        {
            int curr = i;
            int curr_seq = 1;
            while (hashset.count(curr + 1))
            {
                curr++;
                curr_seq++;
            }

            longestStreak = max(longestStreak, curr_seq);
        }
    }
}
int main()
{

    return 0;
}