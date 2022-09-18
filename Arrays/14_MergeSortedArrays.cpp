#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Speciality of this question here they had given whitespaces as 0's and we have to do implace merging of the array , we don't have to use any extra space
//element insertion inside the array in reverse manner
void MergeSorted(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }

    while (i >= 0)
    {
        nums1[k--] = nums1[i--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

void print(vector<int> nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int> nums1;

    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);

    MergeSorted(nums1, 3, nums2, 3);
    print(nums1);
    return 0;
}