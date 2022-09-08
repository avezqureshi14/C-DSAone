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

// Time Complexity is O(1)
// Space Complexity is O(h)

class BSTIterator
{

    stack<Node *> myStack;

public:
    // Constructor for the class
    BSTIterator(Node *root)
    {
        pushAll(root);
    }

    void pushAll(Node *node)
    {
        while (node != NULL)
        {
            myStack.push(node);
            node = node->left;
        }
    }

    // Function to print next element of BST
    int next()
    {
        Node *frontNode = myStack.top();
        myStack.pop();
        pushAll(frontNode->right);
        return frontNode->data;
    }

    // Function to check whether the node has the next, it can be confirmed by checking whether stack is empty
    bool hasNext()
    {
        return !myStack.empty();
    }
};

// Function to iterate
void iterator(BSTIterator it)
{
    while (!it.hasNext())
    {
        cout << it.next() << " ";
    }
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    // //function of the class
    // BSTIterator itr(root);

    // //function to test iterator
    // iterator(itr);

    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1