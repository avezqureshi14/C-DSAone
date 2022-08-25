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

Node *CreateBinaryTree(Node *root)
{
    cout << "Enter data " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (root->data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = CreateBinaryTree(root->left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = CreateBinaryTree(root->right);

    return root;
}

bool isLeaf(Node *node)
{
    if (node->left == NULL)
    {
        return true;
    }
    if (node->right == NULL)
    {
        return true;
    }
    return false;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left) // if curr's left exists then move further
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right) // if curr's right exists then move further
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    // reversing the right boundary
    for (int i = temp.size() - 1; i >= 0; i++)
    {
        res.push_back(temp[i]);
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if(root->left){
        addLeaves(root->left,res);
    }

    if(root->right){
        addLeaves(root->right,res);
    }
}


vector<int>printBoundary(Node*root){
    vector<int>res;
    if(root == NULL){
        return res;
    }

    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
    
    
}

int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);

    vector<int>res = printBoundary(root);

    for(int i:res){
        cout<<i<<" ";
    }

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

// 1 2 3 -1 4 5  6 -1 -1 -1 -1 -1 7 -1 8 9 10 -1 -1 11 -1 -1 -1