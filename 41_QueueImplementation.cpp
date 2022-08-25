#include <iostream>
using namespace std;

/* Linked List Queue Implementation

class Node{
public:
    Node*next;
    int data;
};

class Queue{
    Node*front = NULL;
    Node*rear = NULL;
    void enqueue(int new_data)
    {
        Node*new_node = new Node();
        new_node->data = new_data;
        if (front==NULL)
        {
            front = rear = new_node;
        }
        rear->next = new_node; //pehla rear ke next ko new_node banao uske baad rear ko bhi aage push karo
        rear = new_node;
        
    }
    int dequeue()
    {
           if (front==NULL)
           {
             cout<<"No elements exists in the Queue"<<endl;
           }
           int result = front->data;
           front = front->next;
           free(front);
           return result;
           
    }
};
*/

class Queue{
public:
    int front, rear, size;
    int capacity;
    int *arr[];
};

int main()
{
    
    return 0;
}