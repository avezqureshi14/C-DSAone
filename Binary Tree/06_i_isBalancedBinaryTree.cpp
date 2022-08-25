#include <iostream>
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

int height(Node*node)
{
    //base case
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left,right) + 1;
    return ans;
    //Time Complexity O(n)
    //Space Complexity O(height )
    //Worst Case Space Complexity O(n) for Skew Tree 
}


bool isBalanced(Node*root)
{
    //base case
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left)) - height(root->right) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else{
        return false;
    }
    
    
}
int main()
{
    
    Node*root = NULL;

    root = buildTree(root);

    if (isBalanced(root) == 1)
    {
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    
    
    return 0;
}

//Time Complexity of this program is O(n^2)