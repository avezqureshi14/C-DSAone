
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;

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

    cout << "Enter the data to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void subt(Node *t, vector<int> &v, bool treeSide)
{
    if (!t)
    {
        v.push_back(0);
        return;
    }

    v.push_back(t->data);

    if (treeSide)
    {
        subt(t->left, v, treeSide);
        subt(t->right, v, treeSide);
    }
    else
    {
        subt(t->right, v, treeSide);
        subt(t->left, v, treeSide);
    }
}

bool isSymmetric(Node *root)
{
    vector<int> side1, side2;
    subt(root->left, side1, true);
    subt(root->right, side2, false);

    return side1 == side2;
}

int main()
{

    Node *root = NULL;

    root = buildTree(root);

    bool res = isSymmetric(root);

    if (res == true)
    {
        cout << "Symmetric Tree " << endl;
    }
    else
    {
        cout << "Asymmetric Tree " << endl;
    }

    return 0;
}
// 1 2 4 -1 -1 3 -1 -1 3 -1 -1
// Time Complexity of this program is O(n)
// Space Complexity of this program is O(n)