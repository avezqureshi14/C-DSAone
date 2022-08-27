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

// Time Complexity O()

int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *Solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    // base case
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int position = findPosition(in, element, n);

    // recursive call
    root->left = Solve(in, pre, index, inorderStart, position - 1, n);
    root->right = Solve(in, pre, index, position + 1, inorderEnd, n);

    return root;
}

Node *buildTreeFromInorderPreorder(int in[], int pre[], int n)
{

    int preOrderIndex = 0;
    Node *ans = Solve(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

int main()
{
    int n = 6;
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};

    Node *res = buildTreeFromInorderPreorder(in, pre, n);
    cout << res->data << " ";

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1