#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ReverseSentence(string s)
{
    stack<string> stk;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word = word + s[i];
            i++;
        }

        stk.push(word);
    }

    while (!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }

}

int main()
{
    string s = "Avez is a Good Boy";

    ReverseSentence(s);
    

    return 0;
}