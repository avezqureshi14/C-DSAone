#include <iostream>
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

Node *Create(Node *root)
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
    root->left = Create(root->left);
    cout << "Enter the data to the right of " << data << endl;
    root->right = Create(root->right);

    return root;
}

bool Search(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }

    while (root != NULL && root->data != val)
    {
        root = val > root->data ? root->right : root->left;
    }
    return root;
}

int CeilInBST(Node *root, int key)
{
    int ceil = -1;
    while (root != NULL)
    {

        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}

int main()
{
    Node *root = NULL;
    root = Create(root);
    cout << CeilInBST(root, 9);
    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1
