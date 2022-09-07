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




// Time Complexity is O(N)
// Space Complexity is O(N)

void Inorder(Node*root, vector<int>&inorderVector){
    if (root == NULL)
    {
        return ;
    }

    Inorder(root->left,inorderVector);
    inorderVector.push_back(root->data);
    Inorder(root->right,inorderVector);
}

bool TwoSumInBST(Node*root,int target){
    vector<int> InorderVal;
    Inorder(root,InorderVal);
    int i = 0, j = InorderVal.size() - 1;

    while (i<j)
    {
        int sum = InorderVal[i] + InorderVal[j];
        if (sum == target)
        {
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
        
    }

    return false;
    

}



int main()
{
    Node *root = NULL;

    root = buildTree(root);
    bool res = TwoSumInBST(root,9);
    if (res == true)
    {
        cout<<"Yeah!";
    }
    else{
        cout<<"Nope!";
    }
    
   

    return 0;

}

// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1