#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
};

//Traversal
void print(Node*n)
{
    while (n != NULL)
    {
        cout<<n->data<<"->";
        n = n->next;
    }
    
    
}

//Insertion after a given Node
void pushafter(Node*prev_node, int new_data)
{
    Node*new_node = new Node();
    new_node->data = new_data;
    
    //Jo pehle ka prev_node ka next tah usko abhi new_node ka next banao
    //naya           //pehle
    new_node->next = prev_node->next;
    
    //Aur abhi prev_node ka next kaun rahega ? Ans: new_node
    prev_node->next = new_node;
}

// Insertion at end 
void pushAtend(Node**head_ref, int new_data)
{
    Node*last;
    Node*new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    while (last->next != NULL)
    {
        last =  last->next;

    }

    last->next = new_node;
}

//Deletion In a Node
void deleteNode(Node**head_ref,int key )
{
    Node*admi = *head_ref;
    Node*admi2 = NULL;

    //If head node itself hold the key
    if (admi != NULL && admi->data == key)
    {
        *head_ref = admi->next;
        delete admi;
        return;
    }

    else
    {
        while (admi != NULL && admi->data != key)
        {
            admi2 = admi;
            admi = admi->next;        
        }

        //If key was not present in the linked list
        if (admi == NULL)
        {
            cout<<"The given Key does not exist in the Linked List"<<endl;
        }

        //Unlink the node from Linked List
        admi2->next = admi->next;


        //Free memory
        delete admi;


        
    
    }
    
}

int main()
{
    Node*head;
    Node*second;
    Node*third;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 15;
    head->next = second;

    second->data = 5;
    second->next = third;
    
    third->data = 25;
    third->next = NULL;

    pushafter(head,70);
    pushAtend(&head,98);
    deleteNode(&head,555);

    print(head);



    return 0;
}