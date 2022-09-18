#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Ques : Find longest length of a part of string without repeating characters
// left = 0, right = 0 (in loop), s[right] wala map meh nahi mila toh jo curr wala element hai usko map meh  add karo aur length = max(length,right-left+1), agar mila toh left ki position change karo left = max(left,map[s[right]+1])   
int LongestSubStringWithoutRepeatingCharacters(string s){
    unordered_map<int,int>map;
    int len = 0;
    int left = 0;
    for (int right = 0; right < s.length(); right++)
    {
        if (map.find(s[right]) != map.end())
        {
            left =  max(left,map[s[right]]+1);
        }
        map[s[right]] = right;
        len = max(len,right-left+1);
    }

    return len;


    
}

int main()
{
    string s = "abcaabcdba";
    int res = LongestSubStringWithoutRepeatingCharacters(s);
    cout<<"Length of Longest SubString Without Repeating Characters "<<res;

    return 0;
}