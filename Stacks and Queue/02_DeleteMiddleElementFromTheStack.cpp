#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive Call
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void deleteMiddle(stack<int> &inputStack, int n)
{
    int count = 0;
    solve(inputStack, count, n);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    deleteMiddle(s, s.size());
    print(s);

    return 0;
}