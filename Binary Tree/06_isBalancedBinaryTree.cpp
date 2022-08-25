#include <iostream>
#include <algorithm>
using namespace std;
//A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree

class Node{
public:
    Node*left;
    Node*right;
    int data;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node*root)
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter the data to the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;    
}

pair<bool,int> isBalancedFast(Node*root)
{
    if (root==NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second)<=1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second) + 1 ;
    
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    
    return ans;
}

bool isBalanced(Node*root)
{
    return isBalancedFast(root).first;
}


int main()
{

    Node*root = NULL;
    root = buildTree(root);
    
    if(isBalanced(root) == 1)
    {
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree is Unbalanced"<<endl;
        
    }
    
    return 0;
}

//Time Complexity of this program is O(n)
