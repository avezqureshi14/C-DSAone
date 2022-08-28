#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

/*
1] Save next wali node ka pointer (matlab ab cur<->temp ki jodhi banti ti)
2] Ab cur<->temp ki jodhi todho aur prev<->cur ki jodhi banao
3] prev wale pointer ki position ab cur ke saath lao
4] Aur cur wale pointer ki position ab temp ke saath lao
5] Repeat the above Steps 

*/

// Reverse Linked List = Jodhi wala Question 


void reverse(Node**head_ref)
{
    Node*curr = (*head_ref);
    Node*prev = NULL;
    while (curr!=NULL)
    {
       Node*temp = curr->next;
       curr->next = prev; //breaking old old current link
       prev = curr;
       curr = temp; 
    }
    *head_ref =  prev;

}


void print(Node*n)  
{
    while (n != NULL)
    {
        cout<<n->data<<"->";
        n = n->next;    
    }
    
    
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 45;
    head->next = second;

    second->data = 50;
    second->next = third;

    third->data = 44;
    third->next = NULL;

    print(head);
    reverse(&head);
    cout<<endl;
    print(head);



    return 0;
}