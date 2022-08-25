#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    Node *root = NULL;

    //creating a Tree
    root = buildTree(root);
    
    return 0;
}