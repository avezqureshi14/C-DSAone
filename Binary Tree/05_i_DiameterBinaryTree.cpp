#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;

Node(int val)
{
    this->data = val;
    this->left = NULL;
    this->right = NULL;
}
};

Node *buildTree(Node*root)
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root = new Node(data);
    if (root->data == -1)
    {
        return NULL;
    }

    cout<<"Enter the data to the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to the right of "<<data<<endl;
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

int Diameter(Node*root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = Diameter(root->left);
    int op2 = Diameter(root->right);
    int op3 = height(root->left) + height(root->right)+1;

    int ans = max(op1,max(op2,op3));

    return ans;
}

int main()
{
    Node*root = NULL;
    root = buildTree(root);
    int re = Diameter(root);
    cout<<"Diameter of the Tree is "<<re;
    return 0;
}