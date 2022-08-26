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

// Time Complexity O()

void LeftView(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // we entered into a new level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    LeftView(root->left, ans, level + 1);
    LeftView(root->right, ans, level + 1);
}

vector<int> LeftView(Node *root)
{
    vector<int> ans;
    LeftView(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1