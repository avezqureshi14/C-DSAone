#include <iostream>
#include <algorithm>
using namespace std;
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

pair <bool,int> isSumTreeFast(Node*root)
{
    //Base Cases
    if (root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data == leftAns.second + rightAns.second;

    pair<bool,int> ans;

    if (left && right && condition)
    {
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
    }
    else{
        ans.first = false;
    }
    return ans;
    
    
    
}

bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    Node*root = NULL;
    root = buildTree(root);

    if(isSumTree(root) == 1){
        cout<<"Yes a SumTree"<<endl;
    }
    else{
        cout<<"Not a SumTree"<<endl;
    }
   
    
        
    return 0;
}

