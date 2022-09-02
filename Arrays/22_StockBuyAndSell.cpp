#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MaxProfit(vector<int>&prices){
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice,prices[i]);
        maxPro = max(maxPro,prices[i] - minPrice);
    }
    return maxPro;
    
}
int main()
{
    vector<int>Prices;
    Prices.push_back(1);
    Prices.push_back(2);
    Prices.push_back(3);
    Prices.push_back(4);
    cout<<"The Maximum Profit earned will be " <<MaxProfit(Prices)<<endl;

    
    return 0;
}