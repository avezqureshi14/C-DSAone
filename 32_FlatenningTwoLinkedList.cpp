#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node*bottom;
};


void print(Node*n)
{
    while (n!=NULL)
    {
       cout<<n->data<<"->";
       n = n->bottom; 
    }
    cout<<"NULL";                                           
    
}

Node*mergeTwoLists(Node*a,Node*b)
{
    Node *temp = new Node();
    temp->data = 0;
    Node *res = temp;

    while (a != NULL && b!= NULL)
    {
        if(a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
    {
        temp->bottom = b;

    }
    else{
        temp->bottom = a;
    }

    return res -> bottom;
    
    
}

//root matlab upar wali main linked list

Node *flatten(Node*root)
{
    if (root == NULL || root->next == NULL )
    {
        return root;
    }

    //now merge
    root = mergeTwoLists(root,root->next);
    
    //recur for list on right
    root->next = flatten(root->next);


    return root;
    // this return will again move into the flatten function

    
}

int main()
{
    //roots(main) Node
    Node*head = new Node();
    Node*second = new Node();
    Node*third = new Node();
    Node*fourth = new Node();

    //Bottom Node
    Node*h2 = new Node();
    Node*h3 = new Node();
    Node*h4 = new Node();

    Node*s2 = new Node();

    Node*t2 = new Node();
    Node*t3 = new Node();

    Node*f2 = new Node();
    Node*f3 = new Node();
    Node*f4 = new Node();

    head->next = second;
    head->bottom = h2;
    head->data = 5;

    second->next = third;
    second->bottom = s2;
    second->data = 10;

    third->next = fourth;
    third->bottom = t2;
    third->data = 19;

    fourth->next = NULL;
    fourth->bottom = f2;
    fourth->data = 28;

    h2->bottom = h3;
    h2->next = NULL;
    h2->data = 7;

    h3->bottom = h4;
    h3->next = NULL;
    h3->data = 8;

    h4->bottom = NULL;
    h4->next = NULL;
    h4->data = 30;

    s2->bottom = NULL;
    s2->next = NULL;
    s2->data = 20;

    t2->bottom = t3;
    t2->next = NULL;
    t2->data = 22;

    t3->bottom = NULL;
    t3->next = NULL;
    t3->data = 50;

    f2->bottom = f3;
    f2->next = NULL;
    f2->data = 35;

    f3->bottom = f4;
    f3->next = NULL;
    f3->data = 40;

    f4->bottom = NULL;
    f4->next = NULL;
    f4->data = 50;
    print(head);
    cout<<endl;

    flatten(head);
    print(head);

    


    return 0;
}