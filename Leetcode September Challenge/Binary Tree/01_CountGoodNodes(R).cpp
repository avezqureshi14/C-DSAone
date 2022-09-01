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

// We will be solving this problem using Preorder Traversal, First lets know what is the good node in a binar tree

// Good Nodes : While traversal consider we get a node which is greater in value than the previous node which we got , then this node is called as good node and if we get an node which was smaller in value than the previous node then we say it as bad node ,
// So in short we have to count how many nodes are there which are in the increasing order

// Time Complexity = O(n)
// Space Complexity = O(logn)
// Worst Space Complexity = O(height) or O(n) //research a bit more on space complexity for this question
int ans = 0;

void PreOrder(Node *root, int maxi)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= maxi)
    {
        ans++;
        maxi = root->data;
    }

    PreOrder(root->left, maxi);
    PreOrder(root->right, maxi);
}

int goodNodes(Node *root)
{
    int maxi = INT_MIN;
    PreOrder(root, maxi);
    return ans;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    int res = goodNodes(root);
    cout << "The number of good nodes in the given Binary Tree are " << res << endl;

    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1