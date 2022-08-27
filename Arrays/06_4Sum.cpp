#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &num, int target)
{
    vector<vector<int>> result;
    if (num.empty())
    {
        return result;
    }
    int n = num.size();
    sort(num.begin(), num.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target2 = target - num[j] - num[i];

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int twoSums = num[left] + num[right];
                if (twoSums < target2)
                {
                    left++;
                }
                else if (twoSums > target2)
                {
                    right--;
                }
                else
                {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[left];
                    quadruplet[3] = num[right];
                    result.push_back(quadruplet);

                    // Processing the duplicates which left will encounter
                    while (left < right && num[left] == quadruplet[2])
                    {
                        ++left;
                    }
                    // Processing the duplicates which right will encounter
                    while (left < right && num[right] == quadruplet[3])
                    {
                        --right;
                    }
                }
            }

            while (j + 1 < n && num[j + 1] == num[j])
            {
                ++j;
            }
        }
        while (i + 1 < n && num[i + 1] == num[i])
        {
            ++i;
        }
    }

    return result;
}

int main()
{
    vector<int> num;
    num.push_back(4);
    num.push_back(3);
    num.push_back(3);
    num.push_back(4);
    num.push_back(4);
    num.push_back(2);
    num.push_back(1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(1);
    vector<vector<int>> res = fourSum(num, 9);
    for (vector<int> i : res)
    {
        cout << endl;
        for (int j : i)
        {
            cout << j << " ";
        }
    }

    return 0;
}

// Time Complexity O(n^3)
// Main Points
/*
 1. Just avoid Duplicates
 2. i = 0, j = i + 1, left = j + 1 , right = n - 1
*/