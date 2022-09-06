#include <iostream>
using namespace std;
class Node{
public:
    Node*next;
    int data;
};

Node*removeElements(Node*head, int val){
    if (head == NULL)
    {
        return NULL;
    }
    Node*dummy = new Node();
    dummy->data = -1;

    dummy->next = head;
    Node* tail = dummy;
    while (tail != NULL && tail->next != NULL)
    {
        if (tail->next->data == val)
        {
            Node*temp = tail->next;
            tail->next = temp->next;
            delete temp;
        }
        else{
            tail = tail -> next;
        }
        
    }
    return dummy->next;
    
}

void print(Node*n){
    while (n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    
}

int main()
{
    Node*head = new Node();
    Node*second = new Node();
    Node*third = new Node();
    Node*fourth = new Node();
    Node*fifth = new Node();
    Node*sixth = new Node();
    
    head->data = 15;
    head->next = second;
    
    second->data = 5;
    second->next = third;
    
    third->data = 6;
    third->next = fourth;
    
    fourth->data = 7;
    fourth->next = fifth;
    
    fifth->data = 5;
    fifth->next = sixth;
    
    sixth->data = 50;
    sixth->next = NULL;

    removeElements(head,6);
    print(head);
    return 0;
}