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
vector<double> LevelOrderTraversal(Node *root)
{
    vector<double> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    vector<int> store;
    // Push all the elements into the Queue
    q.push(root);

    // For each loop there will be a new level
    while (!q.empty())
    {
        int sum = 0;
        double size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            sum = sum + curr->data;
            if (curr->left) // agar temp ka left hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(curr->left);
            }

            if (curr->right) // agar temp ka right hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(curr->right);
            }
        }

        double avg = sum / size;
        ans.push_back(avg);
    }

    return ans;
}

int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);
    for (double i : LevelOrderTraversal(root))
    {
        cout << i << " ";
    }

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1