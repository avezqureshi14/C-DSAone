#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '-' || ch == '*' || ch == '/')
        {
            stack.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;

                while (stack.top() != '(')
                {
                    char top = stack.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false; //if we get redundant as false then just pop out that operator 
                    }
                    stack.pop(); //this not the else condition it is the part of the process

                    //we have to pop till the time we will be not getting any opening bracket, if we get any opening bracket then just break the above loop
                }
                if (isRedundant == true)
                {
                    return true;
                }
                stack.pop(); //this pop operation is to pop the opening bracket , this will be used even if redundant is true or false
            }
        }
    }
    return false; //agar upar se hi return nahi hue aur for loop meh se poora bahar nikale , matlab ki there no redundant parenthesis 
}

int main()
{
    string s = "((a+b))";
    bool res = findRedundantBrackets(s);
    if (res == true)
    {
        cout << "Redundant Brackets are Present " << endl;
    }
    else
    {
        cout << "No Redundant Brackets " << endl;
    }

    return 0;
}