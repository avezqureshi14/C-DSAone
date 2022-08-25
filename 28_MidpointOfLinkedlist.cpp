#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void print(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << "->";
        n=n->next;
    }
}

int Midpoint(Node *head)
{
    Node*fast = head;
    Node*slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *five = new Node();
    Node *six = new Node();

    head->data = 54;
    head->next = second;

    second->data = 56;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 46;
    fourth->next = five;

    five->data = 16;
    five->next = six;

    six->data = 5;
    six->next = NULL;

    cout<< Midpoint(head);


    return 0;
}