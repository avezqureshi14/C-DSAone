#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//cmp : custom competitor

//Time Complexity used is O(nlogn) //if sorting is done
//Space Complexity is O(n);

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        meetings.push_back(p);
    }
    // Why we use this ? and how it works
    // sort(meetings.begin(), meetings.end(), cmp);

    int count = 1;
    int ansEnd = meetings[0].second;

    for (int i = 0; i < n; i++)
    {
        if (meetings[i].first > ansEnd)
        {
            count++;
            ansEnd = meetings[i].second;
        }
        
    }
    return count;
    
}

int main()
{
    int start[] = {2,3,4,6,7,9};
    int end[] = {3,4,5,7,8,10};
    cout<<"The number of Meetings conducted to be are "<<maxMeetings(start,end,6);
    return 0;
}