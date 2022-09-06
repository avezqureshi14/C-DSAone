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
    cout << "Enter the data " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

//Time Complexity is O(n)
//Spafe  Complexity is O(n) in worst case(Skew tree)

Node *pruneTree(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->left = pruneTree(root->left); //jab yaha se return hote tab niche ke condition check karne ka 
    root->right = pruneTree(root->right); //jab yaha se return hote tab niche ke condition check karne ka 
    
    //if root's left and root's right are not equal null then only a zero node can be saved 
    //0->1->NULL (safe for 0th Node) 
    //0->NULL (Oth node will be removed) 
    if (root->left != NULL || root->right != NULL)
    {
        return root;
    }
    if (root->data == 0)
    {
        return NULL;
    }

    return root;
}

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

int main()
{
    Node *root = NULL;

    // creating a Tree
    root = buildTree(root);
    pruneTree(root);
    LevelOrderTraversal(root);

    return 0;
}