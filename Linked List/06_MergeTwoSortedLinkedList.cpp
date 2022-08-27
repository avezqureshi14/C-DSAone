#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
};
/*

//Merge Two SOrted Linked lists
1] If l1 is NULL return l2 and if l2 is NULL return l1  
2] Check whether l1 > l2 , if yes then swap l1 and l2
3] Point result Node to the l1

Inside Loop
1] Create two Loops , both while.., run outer loop till l1 != NULL and l2 != NULL and Point temp Node to NULL
2] Run inner Loop till l1 != NULL and l1->data <= l2->data , during this process assign temp = l1 and move l1 = l1->next
3] If the inner Loop breaks point temp->next = l2 and swap l1,l2
3] And if the outer loop breaks return result Node which was initially pointed to l1
 



*/

Node *mergeTwoLinkedLists(Node *l1, Node *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1->data > l2->data)
    {
        swap(l1, l2);
    }
    Node *result = l1 ;
    while (l1 != NULL && l2 != NULL)
    {
        Node *temp = NULL;
        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return result;
}

void print(Node*n)
{
    while (n!=NULL)
    {
       cout<<n->data<<"->"; 
       n = n->next;
    }
    cout<<"NULL";
    cout<<endl;
    
}

int main()
{
    Node*head1 = new Node();
    Node*h12 = new Node();
    Node*h13 = new Node();
    Node*h14 = new Node();
    Node*h15 = new Node();

    head1->data = 1;
    head1->next = h12;

    h12->data = 3;
    h12->next = h13;
    
    h13->data = 5;
    h13->next = h14;
    
    h14->data = 7;
    h14->next = NULL;


    
    Node*head2 = new Node();
    Node*h22 = new Node();
    Node*h23 = new Node();
    Node*h24 = new Node();
    Node*h25 = new Node();

    head2->data = 2;
    head2->next = h22;

    h22->data = 4;
    h22->next = h23;
    
    h23->data = 6;
    h23->next = h24;
    
    h24->data = 8;
    h24->next = NULL;
   


    Node*result = mergeTwoLinkedLists(head1,head2);
    cout<<"This is the Merged Linked List"<<endl;
    print(result);


    


    return 0;
}