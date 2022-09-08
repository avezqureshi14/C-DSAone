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

// Time Complexity is O(N)
// Space Complexity is O(N)


Node*InorderToBST(int start, int end, vector<int>&inorderVal){
    //base case
    if(start > end){
        return NULL;
    }
    int mid = start+end/2;

    Node*root = new Node(inorderVal[mid]);
    root->left = InorderToBST(start,mid-1,inorderVal);
    root->right = InorderToBST(mid+1,end, inorderVal);

    return root;
}
vector<int> Inorder(Node*root,vector<int>&inorderVector){
    if (root == NULL)
    {
        return inorderVector;
    }
    Inorder(root->left,inorderVector);
    inorderVector.push_back(root->data);
    Inorder(root->right,inorderVector);
    return inorderVector;
}

Node*BalancedBST(Node*root){
    vector<int>inorderVal;
    Inorder(root,inorderVal);

    return InorderToBST(0,inorderVal.size()-1, inorderVal);
}


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

    cout<<"Enter data for inserting in left "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right "<<data<<endl;
    root->right = buildTree(root->right);

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





int main()
{
    Node *root = NULL;
    root = buildTree(root);
    LevelOrderTraversal(root);
    cout<<"Balanced BST"<<endl;
  
    LevelOrderTraversal(BalancedBST(root));





    return 0;

}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1