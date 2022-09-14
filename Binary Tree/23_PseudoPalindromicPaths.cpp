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

void pseudoCount(Node *root, vector<int> &store, int &count)
{
    if (root == NULL)
    {
        return;
    }

    // if we want to count number of occurrences of element , then do the below line
    store[root->data]++;
    pseudoCount(root->left, store, count);
    pseudoCount(root->right, store, count);

    if (root->left == NULL && root->right == NULL)
    {
        int flag = 0; // going to count number of odd occurences, if greater than 1 than it is not a palindromic path

        // it has been said that numbers in the binary tree will be from 1 to 9
        for (int i = 1; i <= 9; i++)
        {
            if (store[i] % 2 != 0)
            {
                flag++;
            }
        }

        if (flag == 1 || flag == 0)
        {
            count++;
        }
    }
    store[root->data]--;
}

int pseudoPalindromicPath(Node *root)
{
    int count = 0;
    vector<int> store(10, 0); // size of 10 initialized all values to zero
    pseudoCount(root, store, count);

    return count;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    int res = pseudoPalindromicPath(root);
    cout << "The number of Palindromic Sustrings are " << res << endl;

    return 0;
}

// 2 3 3 -1 -1 1 -1 -1 1 -1 1 -1 -1