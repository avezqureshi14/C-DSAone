#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ThreeSumI(vector<int> &nums)
{
    set<int> hashset;
    vector<int> ans;
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    hashset.insert(nums[i]);
                    hashset.insert(nums[j]);
                    hashset.insert(nums[k]);
                    for (auto i : hashset)
                    {
                        ans.push_back(i);
                    }
                    res.push_back(ans);
                    while (!ans.empty())
                    {
                        ans.pop_back();
                    }
                }
            }
        }
    }

    return res;
}

vector<vector<int>> ThreeSumII(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    // moves for a
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i];
            while (low < high)
            {
                if (nums[low] + nums[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    res.push_back(temp);

                    while (low < high && nums[low] == nums[low + 1])
                    {
                        low++;
                    }

                    while (low < high && nums[low] == nums[high - 1])
                    {
                        high--;
                    }

                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(-6);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    for (auto i : ThreeSumII(nums))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}