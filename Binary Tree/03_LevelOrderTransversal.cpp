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

// Time Complexity O(N)
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // Push all the elements into the Queue
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana levelcomplete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child Nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left) // agar temp ka left hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(temp->left);
            }

            if (temp->right) // agar temp ka right hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(temp->right);
            }
        }
    }
}
//method to be used in an interview , Dry run this ans check when there  is need to insert in matrix
vector<vector<int>> levelOrder(Node *root)
{
    if (!root)
        return {};
    vector<vector<int>> res;
    queue<Node *> q;
    q.push(root);
    while (q.size())
    {
        int n = q.size();
        vector<int> v;
        while (n--)
        {
            Node *t = q.front();
            q.pop();
            v.push_back(t->data);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        res.push_back(v);
    }
    return res;
}

int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);
    cout << "Printing Level Order Transversal " << endl;
    LevelOrderTraversal(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1