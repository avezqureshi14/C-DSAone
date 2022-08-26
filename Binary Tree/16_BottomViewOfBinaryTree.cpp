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

// Time Complexity O()
vector<int>TopView(Node*root){
    vector<int>ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int,int> topNode;
    queue<pair<Node*,int>>q;

    q.push(make_pair(root,0));

    while (!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();
        Node*frontNode = temp.first;
        int vd = temp.second;

        topNode[vd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left,vd-1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right,vd+1));
        }
        
        
    }

    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
    
    
}


int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);
    vector<int> res = TopView(root);
    for (auto i : res )
    {
        cout<<i <<" ";
    }
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1