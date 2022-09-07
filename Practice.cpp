#include <iostream>
using namespace std;
class ListNode
{
public:
    ListNode *next;
    int data;
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *curr = head;
   

    while (fast != NULL && fast->next != NULL)
    {
        
        if (slow->data == fast->data)
        {
            slow->next = fast->next;
        }
        slow = slow->next;
        fast = fast->next;
    }
    

    return head;
}

void print(ListNode*n){
    while (n!=NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    
}


int main()
{
    ListNode *head = new ListNode();
    ListNode *second = new ListNode();
    ListNode *third = new ListNode();
    ListNode *fourth = new ListNode();
    ListNode *fifth = new ListNode();

    head->data = 2;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 12;
    third->next = fourth;
    fourth->data = 3;
    fourth->next = fifth;
    fifth->data = 3;
    fifth->next = NULL;

    print(deleteDuplicates(head));
    

    return 0;
}