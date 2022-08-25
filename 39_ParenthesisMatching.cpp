#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Parenthesis Matching
// Under a for Loop 1-3
//1  Check if the stack is empty , if empty then push one character of the string into the stack
//2 Then check whether the top element of the stack and current string charcter is satisfying matching condition  , if matching then pop
//3 If the current string character is not matching to the stack top then push current string charcter into the stack
//Outside for loop
//1 If loop ends then check whether stack is empty , if empty then return true else false


bool isMactching(char a, char b)

{
    a == '(' && b == ')' ||
        a == '[' && b == ']' ||
        a == '{' && b == '}';
    return true;
}

bool isParenthesis(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        int curr = str[i];
        if (s.empty())
        {
            s.push(str[i]);
        }
        else if (isMactching(s.top(), str[i]))
        {
            s.pop();
        }
        else
        {
            s.push(str[i]);
        }
    }
    if (s.empty())
    {
        return true;
    }
    return false;
    
}

int main()
{
    string s = "()([])";
    bool res = isParenthesis(s);
    if (res == true)
    {
        cout << "Yes";
    }
    else
    {
        "No";
    }

    return 0;
}