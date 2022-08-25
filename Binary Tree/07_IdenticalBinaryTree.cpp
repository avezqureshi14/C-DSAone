#include <iostream>
using namespace std;
class Node{
public:
    Node*left;
    Node*right;
    int data;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node*root)
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter the data to the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;    
}

bool isIdentical(Node*r1, Node*r2)
{
    //base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
    {
        return true;
    }
    else{
        return false;
    } 
    
    
    
}

int main()
{
    Node*root1 = NULL;
    root1 = buildTree(root1);
    Node*root2 = NULL;
    root2 = buildTree(root2);

    if (isIdentical(root1,root2) == 1)
    {
        cout<<"Identical Trees"<<endl;
    }
    else{
        cout<<"Not Indentical"<<endl;
    }
    
        
    return 0;
}