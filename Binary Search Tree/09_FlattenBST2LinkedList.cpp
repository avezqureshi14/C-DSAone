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

class ListNode{
    public:
    ListNode*next;
    int Listdata;
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




// Time Complexity is O(N)
// Space Complexity is O(N)

void Inorder(Node*root,vector<int>inorderVector){
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left,inorderVector);
    inorderVector.push_back(root->data);
    Inorder(root->right,inorderVector);
    
}


Node*Flatten(Node*root){
    vector<int>inorderVal;
    Inorder(root,inorderVal);
    int n = inorderVal.size();

    Node*newRoot = new Node(inorderVal[0]);

    Node*curr = newRoot;

    for (int i = 1; i < n; i++)
    {
        Node*temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
    

}

void print(Node*n){
    while (n!=NULL)
    {
        cout<<n->data<<" ",
        n = n->right;
    }
    
}


int main()
{
    Node *root = NULL;

    root = buildTree(root);
    
    print(Flatten(root));




    return 0;

}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1