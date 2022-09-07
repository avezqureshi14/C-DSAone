#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>&nums){
    int size = nums.size();
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == num1)
        {
            count1++;
        }
        else if(nums[i] == num2){
            count2++;
        }
        else if ( count1 == 0 ){
            num1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0){
            num2 = nums[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }

    vector<int> ans;
    count1 = count2 = 0;
    for(i = 0; i<size; i++){
        if (nums[i] == num1)
        {
            count1++;
        }
        else if(nums[i] == num2){
            count2++;
        }
        
    }

    if(count1 > size/3){
        ans.push_back(num1);
    }
    if (count2 > size/3)
    {
        ans.push_back(num2);
    }

    return ans;
    
    
}
int main()
{
    vector<int>nums;
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(5);

    for(int i : majorityElement(nums)){
        cout<<i << " ";
    }
    return 0;
}