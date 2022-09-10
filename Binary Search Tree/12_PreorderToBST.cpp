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


//Time Complexity O(N)
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
            cout<<temp->data<<" ";

            if (temp->left) //agar temp ka left hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(temp->left);
            }

            if (temp->right) //agar temp ka right hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(temp->right);
            }
        }
    }
}

Node*Solve(vector<int>&PreOrder, int mini, int maxi, int &i){
    if (i >= PreOrder.size())
    {
        return NULL;
    }

    if((PreOrder[i] < mini) || (PreOrder[i] > maxi)){
        return NULL;
    }

     Node*root = new Node(PreOrder[i++]);
    root->left = Solve(PreOrder,mini,root->data,i);
    root->right = Solve(PreOrder,root->data,maxi,i);
    return root;
    
}

Node*PreOrderToBST(vector<int>&PreOrder){
    int mini = INT_MIN;
    int maxi = INT_MAX;

    int i = 0;
    return Solve(PreOrder,mini,maxi,i);
}


int main()
{
    // Node *root = NULL;
    // root = CreateBinaryTree(root);
    // cout << "Printing Level Order Transversal " << endl;
    // 10, 5, 1, 7, 40, 50 
    vector<int>PreOrder ;
    PreOrder.push_back(20);
    PreOrder.push_back(10);
    PreOrder.push_back(5);
    PreOrder.push_back(15);
    PreOrder.push_back(13);
    PreOrder.push_back(35);
    PreOrder.push_back(30);
    PreOrder.push_back(42);
    LevelOrderTraversal(PreOrderToBST(PreOrder));
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1