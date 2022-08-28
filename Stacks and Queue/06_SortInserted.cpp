#include <iostream>
#include <stack>
using namespace std;
//Insert in Sorted Way
void SortInserted(stack<int>&stack,int num)
{


    if (stack.empty()  ||  stack.top() < num )
    {
        stack.push(num);
        return;
    }

    int store = stack.top();
    stack.pop();
    SortInserted(stack,num);
    stack.push(store);
    
}

void print(stack<int> s){
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
    s.push(3);
    s.push(4);
    SortInserted(s,5);
    print(s);

    
    return 0;
}