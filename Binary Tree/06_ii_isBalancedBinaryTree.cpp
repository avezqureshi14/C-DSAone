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




int HeightBal(Node*root){
    if(root==NULL) return 0;

    int leftHeight = HeightBal(root->left);

    if (leftHeight == -1)
    {
        return -1;
    }
    int rightHeight = HeightBal(root->right);

    if (rightHeight == -1)
    {
        return -1;
    }

    if(abs(leftHeight - rightHeight)>1) return -1;
    return max(leftHeight,rightHeight) + 1;
    
}

bool isBalanced(Node*root){
    if (HeightBal(root) == -1) //if the HeightBal will return -1 then it is Unbalanced 
    {
        return false;
    }
    
    return true; 
}

int main()
{
    
    Node*root = NULL;

    root = buildTree(root);

    bool res = isBalanced(root);

    if (res == true)
    {
        cout<<"Balanced Tree "<<endl;
    }
    else{
        cout<<"Unbalanced Tree "<<endl;
    }
    

  
    
    
    return 0;
}
// 1 2 4 -1 -1 3 -1 -1 3 -1 -1
//Time Complexity of this program is O(n)
//Space Complexity of this program is O(n)