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


void Inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left, in);
    in.push_back(root->data);
    Inorder(root->right, in);
}

// Time Complexity O(n+m)
// Space Complexity O(n+m)

Node *InorderToBST(int start, int end, vector<int> &inorderVal)
{
    // base case
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;

    Node *root = new Node(inorderVal[mid]);
    root->left = InorderToBST(start, mid - 1, inorderVal);
    root->right = InorderToBST(mid + 1, end, inorderVal);

    return root;
}

vector<int> mergeArrays(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }

    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

Node *MergeBST(Node *root1, Node *root2)
{
    // Step 1 : Store Integer
    vector<int> bst1, bst2;
    Inorder(root1, bst1);
    Inorder(root2, bst2);

    vector<int> mergeArray = mergeArrays(bst1, bst2);

    int start = 0, end = mergeArray.size() - 1;
    return InorderToBST(start, end, mergeArray);
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
    Node *root1 = NULL;
    root1 = buildTree(root1);
    Node *root2 = NULL;
    root2 = buildTree(root2);

    Node*root3;
    root3 = MergeBST(root1,root2);
    LevelOrderTraversal(root3);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1