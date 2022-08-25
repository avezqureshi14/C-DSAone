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

// Time Complexity is O(log 2n)
//Just greater than the given key or equal to the given key
int findCeil(Node *root, int key)
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

    root = buildTree(root);
    int res = findCeil(root, 9);
    cout << "The ceil of the given node of the BST is " << res;

    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1