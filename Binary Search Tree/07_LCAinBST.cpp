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

// Time Complexity is O(height)
// Space Complexity is O(n) //if done using recursion(stack space) using while loop it will take O(1)

// We are passing here the integer value so this Algo will work even if one of the element is present(from the given) in our BST it is better to  pass the Nodes pointer

int search(Node *root, int val)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root != NULL && root->data != val)
    {
        if (root->data > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root->data;
}

int LCA(Node *root, int p, int q)
{
    if (root == NULL)
    {
        return -1;
    }

    int curr = root->data;

    if (curr < p && curr < q)
    {
        return LCA(root->right, p, q);
    }

    if (curr > p && curr > q)
    {
        return LCA(root->left, p, q);
    }

    return root->data;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    int res;
    int val1 = 7;
    int val2 = 9;
    int res1 = search(root,val1);
    int res2 = search(root,val2);
    if (res1 == val1 && res2 == val2){
        res = LCA(root,val1, val2);
        cout << "The Lowest Common Ancestor of the given  nodes our BST is " << res << endl;
    }
  
    



    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1