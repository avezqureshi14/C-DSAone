#include <iostream>
#include <stack>
using namespace std;

void SortInserted(stack<int> &stack, int num){
    if(stack.empty() || stack.top() < num){
        stack.push(num);
        return ;
    }

    int store = stack.top();
    stack.pop();
    SortInserted(stack,num);
    stack.push(store);
}

void SortedStack(stack<int> &stack){
    if (stack.empty()){
        return;
    }

    int store = stack.top();

    stack.pop();
    SortedStack(stack);
    SortInserted(stack,store);
}

void print(stack<int>s)
{
    while (!s.empty())
    {
    cout<<s.top()<<" ";
    s.pop();
    }
}

int main()
{
    stack<int>s;
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(3);
    SortedStack(s);

    print(s);

    return 0;
}