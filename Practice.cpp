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

Node *findRight(Node *root)
{
    if (root == NULL)
    {
        return root;
    }

    root = root->right;
}

Node *helper(Node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }

    Node *rightNode = root->right;
    Node *lastRight = findRight(root->left);
    lastRight->right = rightNode;
    return root->left;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return helper(root->left);
    }
    Node *dummy = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
            }
            else
            {
                root = root->right;
            }
        }
    }

    return dummy;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    cout << "Before Deleting " << endl;
    LevelOrderTraversal(root);
    cout << endl;
    cout << "After Deleting " << endl;
    deleteNode(root, 12);
    LevelOrderTraversal(root);

    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1