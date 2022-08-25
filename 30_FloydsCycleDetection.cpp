#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node*next;
};
void print(Node*n)
{
    while (n!=NULL)
    {
        cout<<n->data<<"->"; 
        n = n->next; 
    }
    
}

//Ek SLow pointer lene ka , ek fast pointer lene ka slow pointer ko ek kadam chalane ka , fast pointer ko doh kadam chalane ka , firr fast pointer aur slow pointer jaha par milte waha par loop detected 
//Basically Endless Loop kab nahi rehta jab last pointer NULL ko point kara raha hai agar last pointer aur kisi pointer ko point karta hai toh definitely endless loop tayar ho jata hai
Node* Detect(Node*head)
{
    Node*slow = head;
    Node*fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            cout<<"Loop Detected"<<endl;
            return slow;
        }
        
        
    }

    cout<<"No Loop Detected"<<endl;
    return slow;


    

}

int DetectFirstNode(Node*head)
{
    Node*meet = Detect(head);
    Node*start = head;
    Node*front = head;

    while (meet != start)
    {
        start = start->next;
        meet = meet->next;


    }

    return start->data;
    
}

void removeCycle(Node*head)
{
    Node*slow = head;
    Node*fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow!=fast);

    //we are using do...while loop above because we want to separate slow and fast pointer

    slow->next = NULL;
    
}

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

    Detect(head);
    // removeCycle(head);
    cout<<"The Point is "<<DetectFirstNode(head);

    return 0;
}

//Endless Loop creation
//Basically Endless Loop kab nahi rehta jab last pointer NULL ko point kara raha hai agar last pointer aur kisi pointer ko point karta hai toh definitely endless loop tayar ho jata hai

//Jionet@SInhgadInstitute