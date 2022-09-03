#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// two pointer iterative
void reverseString(vector<char> &s)
{
    int n = s.size() - 1;
    int i = 0;
    int j = n;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}
int main()
{

    return 0;
}