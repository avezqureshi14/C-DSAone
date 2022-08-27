#include <iostream>
using namespace std;
class Node{
   public: 
    char data;
    Node*next;
};


//When we use more than two pointer there is a need of double pointer


Node* midpoint(Node*head)
{
    Node*slow = head;
    Node*fast = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return slow->next; //Midpoint ka next se reverse karna hai
}

Node* reverse(Node*head)
{
    Node*curr = midpoint(head);
    Node*prev = NULL;

    while (curr!=NULL)
    {
        Node*temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;

    
}

bool Palindrome(Node*head){

    Node*curr = head;
    Node*last = reverse(head);
    while (last != NULL)
    {
       if (curr->data != last->data) //Check for data not for a pointer
       {
        return false;
       }
       curr=curr->next;
       last=last->next;
        
    }

    return true;
    


}

//Find the reverse from the next node after the midpoint
//Assign two pointer last and curr, curr pointing head and last pointing to the node  which is returned by the reverse function
//Check till our last is not equal to null that the curr->data is equal to last->data if it is equal then move both pointers forward and if not return false 





void print(Node*n)
{
    while (n!=NULL)
    {
        cout<<n->data<<"->";
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
    Node*seven = new Node();


    head->data = 'r';
    head->next = second;

    second->data = 'a';
    second->next = third;

    third->data = 'c';
    third->next = fourth;

    fourth->data = 'e';
    fourth->next = fifth;

    fifth->data = 'c';
    fifth->next = sixth;

    sixth->data = 'a';
    sixth->next = seven;

    seven->data = 'r';
    seven->next = NULL;

    bool result = Palindrome(head);
    if (result == true)
    {
        cout<<"Yes it is a Palindrome"<<endl;
    }
    else{
        cout<<"It is not a Palindrome"<<endl;
    }
    
        
    return 0;
}