#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// copying string into an uordered map
void Copy(string s)
{
    int n = s.length();
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
    }
    //Printing map
    for (auto i : map)
    {
        cout << i.first << ": " << i.second << endl;
    }
    
}

int main()
{
    string s = "aveza";
    Copy(s);

    return 0;
}