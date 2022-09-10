#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    // For left
    cout << "Enter the data for the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}




// Time Complexity is O(N)
// Space Complexity is O(1)

bool isValidBST(Node*root, long minVal, long maxVal)
{
    if (root == NULL)
    {
        cout<<maxVal;
        return true;
    }

    if (root->data >= maxVal || root->data <= minVal )
    {
        return false;
    }

    return isValidBST(root->left,minVal, root->data) &&
           isValidBST(root->right,root->data, maxVal);
    
    
}

bool isValidBST(Node*root){
    //concept of function Overloading 👇👇👇 means the same function name with the different amount of parameters
    return isValidBST(root,INT_MIN,INT_MAX);
}


int main()
{
    Node *root = NULL;

    root = buildTree(root);
    bool res = isValidBST(root);
    if (res == true)
    {
        cout<<"It is a Valid BST"<<endl;
    }
    else{
        cout<<"It is not a Valid BST"<<endl;
    }
    

    return 0;

}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1
//8 5 4 -1 -1 7 -1 -1 12 10 -1 -1 14 -1 -1 
//8 5 4 3 -1 -1  -1  6 -1 -1  11 10 -1 -1 13 -1 -1 