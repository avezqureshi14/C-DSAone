#include <iostream>
#include <stack>
using namespace std;

int findMinCost(string s)
{
    // odd condition
    if (s.length() % 2 == 1) // if remainder is equal to 1 then it is a odd term
    {
        return -1;
    }

    stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '{')
        {
            stack.push(ch);
        }
        else
        {

            // ch is closed brace
            if (!stack.empty() && stack.top() == '{')
            {
                stack.pop(); // removing the valid string part aside
            }
            else
            {
                stack.push(ch);
            }
        }
    }

    // stack contain invalid expression
    int a = 0, b = 0;
    while (!stack.empty())
    {
        if (stack.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }

        stack.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;

    return ans;
}

int main()
{
    string s = "}}}{}{}}}}";

    cout << "Minmum Cost for Finding the Valid String is " << findMinCost(s) << endl;

    return 0;
}