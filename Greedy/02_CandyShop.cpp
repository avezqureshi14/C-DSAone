#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> candyStore(int candies[], int n, int k){
    sort(candies,candies+n);
    int mini = 0;
    int buy = 0;
    int free = n - 1;

    while (buy <= free)
    {
        mini = mini + candies[buy];
        buy++;
        free = free - k;
    }

    int maxi = 0;
    buy = n-1;
    free = 0;

    while (free <= buy)
    {
        maxi = maxi + candies[buy];
        buy--;
        free = free + k;
    }
    vector<int>ans;
    ans.push_back(mini); 
    ans.push_back(maxi);
    return ans;
    
    
}
int main()
{
    int candies[] = { 3, 2 , 1 , 4};
    int n = 4;
    int k = 2;
    for(auto i : candyStore(candies,n,k)){
        cout<<i <<" ";
    }
    
    return 0;
}