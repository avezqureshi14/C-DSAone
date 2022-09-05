#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// copying string into an uordered map
int FirstUniqueCharacter(string s)
{
    int n = s.length();
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (map[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string s = "avezveza";
    cout << "First Non Repeating character Index is " << FirstUniqueCharacter(s);

    return 0;
}