#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int> &changed)
{
    vector<int> ans;
    int n = changed.size();
    if (n % 2 != 0)
    {
        return ans;
    }
    unordered_map<int, int> map;

    sort(changed.begin(), changed.end());

    for (auto i : changed)
    {
        map[i]++;
    }

    for (auto x : changed)
    {
        if (map[x] == 0)
        {
            continue;
        }
        if (map[x * 2] == 0)
        {
            return {};
        }
        if (map[x]  && map[2 * x])
        {
            ans.push_back(x);
        }

        map[x]--;
        map[x * 2]--;

    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 6, 8};
    for (auto i : findOriginalArray(nums))
    {
        cout << i << " ";
    }
    return 0;
}