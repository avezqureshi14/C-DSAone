#include <iostream>
using namespace std;
class Node{
public:
    Node*next;
    int data;
};


Node*slow(Node*head){
    Node*slow = slow->next;
}
Node*fast(Node*head){
    Node*fast = fast->next->next;
}


do
{
    slow(*head);
    fast(*head);
} while (slow != fast);


int main()
{
    Node*head = new Node();
    Node*second = new Node();
    Node*third = new Node();
    Node*fourth = new Node();
    Node*fifth = new Node();
    Node*sixth = new Node();

    head->data = 5;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 7;
    fourth->next = fifth;

    fifth->data = 6;
    fifth->next = sixth;

    sixth->data = 2;
//Loop created for Testing
    sixth->next = fourth;



    return 0;