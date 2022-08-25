#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*next;
};

Node* newNode(int data)
{
    Node* stackNode = new Node();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(Node* head_ref)
{
    return !head_ref;
}

void push(Node**head_ref, int new_data)
{
    Node*new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref; // 1] new node next rahega hamara head  
    *head_ref = new_node; //This makes the first element of the stack to be new_node by making each elemnt as a head // 2] aur jo hamara head woh new_node hi banega , zahir si baat hai
    cout<<new_data<<" pushed to Stack"<<endl;
}

int pop(Node**head_ref)
{
    if (isEmpty(*head_ref))
    {
        return INT_MIN;
    }
    Node*temp = *head_ref;
    *head_ref = (*head_ref)->next;
    int popped = temp->data;
    free(temp);

    return popped;
    
}

int peek(Node*head_ref)
{
    if (isEmpty(head_ref))
    {
        return INT_MIN;
    }
    return head_ref->data;
    
}

int main()
{
    Node*head = new Node();
    head->next = NULL;

    push(&head,10);
    push(&head,20);
    push(&head,30);

    cout<<pop(&head)<<" popped from the Stack"<<endl;

    cout<<"Top Element is "<<peek(head)<<endl;

    cout<<"Elements Present in Stack : ";
    while (!isEmpty(head))
    {
       cout<<peek(head)<<" ";
       pop(&head); 
    }

    cout<<endl;
    cout<<"Running Empty "<<endl;
    cout<<isEmpty(head);
    
    
    return 0;
}