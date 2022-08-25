#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int LongestSubstring(string s)
{
 unordered_map <char,int> map;
 int len = 0; 
 int left = 0;
 for (int right = 0; right < s.length(); right++)
 {
    if (map.find(s[right]) != map.end())
    {
        left = max(left, map[s[right]]+1);
    }
    map[s[right]] = right; //not adding else to this condition updates value in our Hashmap

    len = max(len, right-left+1);
    
 }

 return len;
 
}

int main()
{
    string s = "abcaabcdba";
    cout<<"The Longest Length of SubString without repeating Characters is "<<LongestSubstring(s);
    return 0;
}