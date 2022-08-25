#include <iostream>
using namespace std;
class Node
{
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

Node *buildTree(Node*root)
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

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


int height(Node*node)
{
    //base case
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left,right) + 1;
    return ans;
    //Time Complexity O(n)
    //Space Complexity O(height )
    //Worst Case Space Complexity O(n) for Skew Tree 
}

int main()
{
    Node*root = NULL;

    //creating a Tree
    root = buildTree(root);
    cout<<"The height of the Binary Tree is "<<height(root);
    cout<<endl;
    
    return 0;
}

//1 2 4 -1 -1 5 -1 -1 3 -1 -1