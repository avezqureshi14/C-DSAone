#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class MyStack{
    int top;

public:
    int a[MAX];

    MyStack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool MyStack::push(int x)
{
    if (top >= (MAX-1))
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else{
        a[++top] = x;
        cout<<x<<" Pushed into the Stack"<<endl;
        return true;
    }
    
}

int MyStack::pop()
{
    if (top<0)
    {
        cout<<"Stack Underflow";
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
    
}

int MyStack::peek()
{
    if(top<0)
    {
        cout<<"Stack is Empty";
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool MyStack::isEmpty()
{
    return (top<0);
}

bool MyStack::isFull()
{
    return (top = (MAX-1));
}

int main()
{
    class MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    //Popping elemnts from the stack
    cout<<s.pop()<<" Popped from Stack"<<endl;

    while(!s.isEmpty())
    {
        s.push(1);
    }

    //Print all element sin the stack 
    cout<<"Elements present in the stack"<<endl;
    while (!s.isEmpty())
    {
        //Print top elements from the stack 
        cout<<s.peek()<<" ";
        //Remove top elements from the stack 
        s.pop();
    }

    
    

    return 0;
}