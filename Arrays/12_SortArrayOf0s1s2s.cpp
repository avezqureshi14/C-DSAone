#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// This just can be done woth sorting but this takes only O(1) whereas sorting takes O(nlogn)
/*
if(0){
    swap(num[low],num[mid])
    low++
    mid++
}
else if(1){
    mid++
}
else if(2){
    swap(num[mid],num[high])
    high--

}
*/

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
            swap(nums[low++], nums[mid++]); // low and mid
            break;
        case 1:
            mid++; // mid
            break;
        case 2:
            swap(nums[mid], nums[high--]); // high
            break;
        }
        // l-m-m-h
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
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    cout << "Before Sorting " << endl;
    print(nums);
    cout << endl;
    cout << "After Sorting " << endl;
    sortColors(nums); //Time Complexity O(1)
    print(nums);
    cout<<endl;
    sort(nums.begin(),nums.end()); //Time Complexity O(nlogn)
    print(nums);
    return 0;
}