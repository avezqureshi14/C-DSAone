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



//without using pair
//Time Complexity is O(N)
//Space Complexity is O(N) 
int heightDiameter(Node*node, int &diameter){
    if(node == NULL){
        return 0;
    }
    int lh = heightDiameter(node->left,diameter);
    int rh = heightDiameter(node->right,diameter);

    diameter = max(diameter,lh + rh); //calculating diameter
    return (max(lh , rh)+1); //returning height
}

int DiameterOfBinaryTree(Node*root){
    int diameter = 0;
    heightDiameter(root,diameter);
    return diameter;
}


int main()
{
    Node*root = NULL;
    root = buildTree(root);
    cout<<"The Diameter of the Binary Tree is "<<DiameterOfBinaryTree(root);
    return 0;
}

// 1 2 4 -1 -1 3 -1 -1 3 -1 -1