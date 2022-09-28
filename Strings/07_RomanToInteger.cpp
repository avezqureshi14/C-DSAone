#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    unordered_map<char, int> map = {
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    int res = map[s.back()];
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (map[s[i]] < map[s[i + 1]])
        {
            res = res - map[s[i]];
        }
        else
        {
            res = res + map[s[i]];
        }

    }
        return res;
}
int main()
{
    string s = "MCMXCIV";
    cout<<"The Integer of given Roman number is as follows "<<romanToInt(s);
    
    return 0;
}