#include <iostream>
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

//Small moves left
//Greater moves right


//Time Complexity is O(log n)
Node *Search(Node *root, int val)
{
    while (root != NULL && root->data != val) //Jab tak root null nahi hota aur root ka data val ke equal nahi hota tab tak, while loop chalao, agar apan jo node peh kade hai use ke data se agar apni val choti hai toh left meh jane ka agar apni val node ke data se badi hai toh right meh jane ka 
    {
        root = val < root->data ? root->left : root->right; 
    }
    return root;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    int val = 24;

    Node *res = Search(root, val);
    if (res->data == val)
    {
        cout << "Yeah! the value " << val << " is present in our BST" << endl;
    }


return 0;
}


// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1