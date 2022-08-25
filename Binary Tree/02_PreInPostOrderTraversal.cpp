#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node*right;
    Node*left;
};

Node* newNode(int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printPreorder(Node*node)
{
    if (node==NULL)
    {
        return;
    }

    //N
    cout<<node->data<<" ";
    //L
    printPreorder(node->left);
    //R
    printPreorder(node->right);

    
}


void printInorder(Node*node)
{
    if (node==NULL)
    {
        return;
    }

    // L
    printInorder(node->left);
    // N
    cout<<node->data<<" ";
    // R
    printInorder(node->right);

    
}


void printPostorder(Node*node)
{
    if (node == NULL)
    {
        return;
    }

    //L
    printPostorder(node->left);
    //R
    printPostorder(node->right);
    //N
    cout<<node->data<<" ";
    
}



int main()
{
    Node*root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Printing PreOrder"<<endl;
    printPreorder(root);
    cout<<endl;

    cout<<"Printing InOrder"<<endl;
    printInorder(root);
    cout<<endl;

    cout<<"Printing PostOrder"<<endl;
    printPostorder(root);
    cout<<endl;

    
    
    return 0;
}