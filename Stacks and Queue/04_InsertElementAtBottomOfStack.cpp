#include <iostream>
#include <stack>
using namespace std;

//Check the GFG SOlution

void Solve(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    Solve(s, x); 

    s.push(num);
}


stack<int> pushAtBottom(stack<int> myStack, int x)
{

    Solve(myStack, x);
    return myStack;
}
void Print(stack<int>&stack)
{
    while (!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    
    
}



int main(){


    stack<int>n;
    n.push(2);
    n.push(3);
    n.push(4);
    n.push(5);
    cout<<endl;
    cout<<"Before"<<endl;
    Print(n);
    cout<<endl;
    n =  pushAtBottom(n,1);
    Print(n);

    return 0;
}