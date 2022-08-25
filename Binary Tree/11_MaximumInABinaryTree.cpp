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
    cout << "Enter the data" << endl;
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int maximum(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    int res = root->data;
    //res is the every root node
    int left = maximum(root->left);
    int right = maximum(root->right);
    if (left > res)
    {
        res = left;
    }
    if (right > res)
    {
        res = right;
    }

    return res;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    cout << "Maximum Number is " << maximum(root) << endl;
    return 0;
}

// 1 2 4 -1 -1 3 -1 -1 3 -1 -1

// Base Case aise socho ki tumhe bus NULL diya ho aur kohi node na ho , toh tum us question meh kya return karte