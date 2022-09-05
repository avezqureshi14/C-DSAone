#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValidAnagram(string &s, string &t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int n = s.length();
    int m = t.length();
    if (n != m)
    {
        return false;
    }

    return s == t ? true : false;
}

void sortStr(string &s)
{
    sort(s.begin(), s.end());
}

void print(string &s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
}

int main()
{
    string s = "rat";
    string t = "car";
    bool res = isValidAnagram(s, t);
    if (res == true)
    {
        cout << "Yeah! " << endl;
    }
    else
    {
        cout << "Nope " << endl;
    }

    return 0;
}