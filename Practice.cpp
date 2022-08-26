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

int LCA(Node *root, int val1, int val2)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data > val1 && root->data > val2)
    {
        return LCA(root->left, val1, val2);
    }

    if (root->data < val1 && root->data < val2)
    {
        return LCA(root->right, val1, val2);
    }

    return root->data;
}

int maximum(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    int res = root->data;
    int left = maximum(root->left);
    int right = maximum(root->right);

    if (res < left)
    {
        res = left;
    }
    if (res < right)
    {
        res = right;
    }

    return res;
}

bool isValid(Node *root, long minVal, long maxVal)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data <= minVal || root->data >= maxVal)
    {
        return false;
    }

    return isValid(root->left, minVal, root->data) &&
           isValid(root->right, root->data, maxVal);
}

bool isValid(Node *root)
{
    return isValid(root, INT_MIN, INT_MAX);
}

Node *LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
    return root;
}

int Size(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Size(root->left);
    int right = Size(root->right);

    int ans = left + right + 1;

    return ans;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int height = max(left, right) + 1;

    return height;
}

int Diameter(Node *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Diameter(root->left, diameter);
    int right = Diameter(root->right, diameter);

    diameter = max(diameter, (left + right));

    return max(left, right) + 1;
}

int Diameter(Node *root)
{
    int diameter = 0;
    Diameter(root, diameter);
    return diameter;
}

int Bal(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = Bal(root->left);
    if (leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = Bal(root->right);

    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight > 1))
    {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool Balanced(Node *root)
{
    int res = Bal(root);
    if (res == -1)
    {
        return false;
    }
    return true;
}

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
    {
        return true;
    }

    return false;
}

vector<int> VerticalOrderTraversal(Node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int vd = temp.second.first;
        int lvl = temp.second.second;

        nodes[vd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(vd - 1, lvl + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(vd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    vector<int>res = VerticalOrderTraversal(root);
    for(auto i : res){
        cout<<i<<" ";
    }

    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1