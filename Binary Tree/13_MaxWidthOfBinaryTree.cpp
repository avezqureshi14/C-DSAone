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

// Small moves left
// Greater moves right

// Time Complexity is O(n)
// Space Complexity is O(n)
int widthOfBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int mmin = q.front().second; // keeps updating
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curr_id = q.front().second - mmin;
            Node *node = q.front().first; //to get ready to input further two nodes index in out queue
            if (i == 0)
            {
                first = curr_id;
            }
            if (i == size - 1)
            {
                last = curr_id;
            }
            q.pop();
            if (node->left)
            {
                q.push({node->left, curr_id * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, curr_id * 2 + 2});
            }

            ans = max(ans, last - first + 1); //after first iteration move out and check whether queue is empty
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    int res = widthOfBinaryTree(root);
    cout << "Width of the Binary Tree is " << res << endl;
    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1