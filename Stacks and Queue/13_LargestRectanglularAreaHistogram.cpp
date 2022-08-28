#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Here we have to find the largest Rectangular area in the histogram
// 1] Find the prev small 
// 2] Empty the Stack
// 3] Find the next small
// 4] area = max(area, height[i] * (nextSmall[i] - prevSmall[i] + 1))

stack<int> s;

int largestRectangleArea(vector<int> &height)
{
    int n = height.size();
    stack<int> s;

    int prevSmall[n];
    for (int i = 0; i < n; i++)
    {
        int curr = i;
        while (!s.empty() && height[s.top()] >= height[i])
        {
            s.pop();
        } 
        if (s.empty())
        {
            prevSmall[i] = -1;
        }
        else
        {
            prevSmall[i] = s.top()+1;
        }
        s.push(i);
    }

    int nextSmall[n];
    // emptying the stack for reuse
    while (!s.empty())
    {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = i;
        while(!s.empty() && height[s.top()] >= height[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            nextSmall[i] = n-1;
        }
        else
        {
            nextSmall[i] = s.top()-1;
        }
        s.push(i);
    }

    int area = 0;
    for (int i = 0; i < n; i++)
    {
        area = max(area, height[i] * (nextSmall[i] - prevSmall[i] + 1));
    }
    return area;
}

int main()
{
    vector<int> height;
    height.push_back(4);
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(3);
    height.push_back(2);
    height.push_back(4);
    height.push_back(2);
    int result = largestRectangleArea(height);
    cout << "The Largest Rectangular Area is " << result << endl;
    return 0;
}