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

// Time Complexity is O(N)
// Space Complexity is O(N)

void Inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}

bool TWoSum(Node *root, int target)
{
    vector<int> ans;
    Inorder(root, ans);
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        int sum = ans[i] + ans[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return false;
}

Node *Flatten(Node *root)
{
    vector<int> ans;
    Inorder(root, ans);
    Node *new_node = new Node(ans[0]);
    Node *curr = new_node;
    int n = ans.size();
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;
    return new_node;
}

Node *CreateABalancedBST(Node *root)
{
    vector<int> ans;
    Inorder(root, ans);
    int n = ans.size() - 1;
    int start, end, mid;
    start = 0, end = n - 1;

    InorderToBST(root, ans, start, end);
}

Node *InorderToBST(Node *root, vector<int> ans, int start, int end)
{
    int mid = 0;
    while (start < end)
    {
        mid = (start + end) / 2;
    }

    Node *root = new Node(ans[mid]);
    InorderToBST(root->left,ans,0,mid-1);
    InorderToBST(root->right,ans,mid+1,end);

    return root;
}

void print(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " -> ";
        n = n->right;
    }
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    LevelOrderTraversal(root);
    cout<<endl;
    cout<<"Balanced BST"<<endl;
    LevelOrderTraversal(CreateABalancedBST(root));

    return 0;
}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1