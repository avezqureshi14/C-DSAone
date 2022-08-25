#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// If we use sorting for this then Merge Sort will have Time Complexity of  O(nlogn)

//Dutch National FLag ALgorithm 
// : This Algorithm says all the elements from [0 to low -1 = 0 and from high+1 to n = 2 ](here " '=' read as are") 

//take 3 variable low, mid ,high intialize low = 0, mid = 0, high = n- 1
//traverse the array till mid <= high 
//if arr[mid] = 0 , i] swap(arr[low],arr[mid]) ii]mid++, low++
//if arr[mid] = 1, i] mid++
//if arr[mid] = 2 i] swap(arr[low],arr[mid]) ii] high--
//Time complexity is O(n) and Space Complexity is O(1)
void sortColors(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;

    while (mid <= high)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[low++], nums[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(nums[mid], nums[high--]);
            break;
        }
    }
}

void print(vector<int>&nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
    
}

int main()
{
    vector <int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    sortColors(nums);
    print(nums);
    return 0;
}