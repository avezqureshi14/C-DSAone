#include <iostream>
#include <algorithm>
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


Node *buildTree(Node*root)
{
    //Taking data from the user
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;

    //Passing the data to the 1st node
    root = new Node(data);

    //Then writing condition for stoping data acceptance
    if (data == -1)
    {
        return NULL;
    }
    
    // Taking the data for the left node 
    cout<<"Enter the data for inserting in the left "<<data<<endl;
    root->left = buildTree(root->left);
    // Taking the data for the right node 
    cout<<"Enter the data for inserting in the right "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

//first = diameter //second height
pair<int,int> diameterFast(Node*root){
    // base case 
    if (root==NULL)
    {
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left); 
    pair<int,int> right = diameterFast(root->right); 

    int op1 = left.first; //finding the diameter of the left subtree
    int op2 = right.first; //finding the diameter of the right subtree
    int op3 = left.second + right.second + 1; //finding the height of the tree

    pair<int,int> ans;

    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node*root){
    return diameterFast(root).first;
}

int main()
{
    Node*root = NULL;

    root = buildTree(root);
    cout<<"The diameter of the tree is "<<diameter(root);
    return 0;
}