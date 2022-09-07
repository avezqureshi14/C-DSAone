#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
};

Node *RemoveDuplicates(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        while (curr->next != NULL && curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }

        curr = curr->next;
    }
    return head;
}

void print(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *fifth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = fifth;

    fifth->data = 3;
    fifth->next = NULL;

    print(RemoveDuplicates(head));
    return 0;
}