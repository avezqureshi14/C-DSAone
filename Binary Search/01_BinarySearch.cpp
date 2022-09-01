#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int mid = 0;

    int high = nums.size() - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else if (nums[mid] != target && low >= high)
        {
            return -1;
        }
    }
    }
        int main()
        {
            vector<int> nums;
            nums.push_back(12);
            nums.push_back(9);
            nums.push_back(5);
            nums.push_back(3);
            nums.push_back(0);
            nums.push_back(-1);
            cout << "The given target is present at index " << search(nums, 12);
            return 0;
        }