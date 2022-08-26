#include <iostream>
#include <algorithm>
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
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

//ZigZag Traversal is nothing but SImilar to the LevelOrder Traversal

vector <int> ZigZag(Node*root)
{
    vector<int>result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node*>q;
    q.push(root);
    
    bool leftToright = true; //Assign the flag

    while (!q.empty())
    {
        int size= q.size(); 
        vector<int>ans(size ); //Create a vector to store the ans which must be the size of  queue which you have created

        //Level Process
        for (int i = 0; i < size; i++)
        {
            Node*frontNode = q.front();
            q.pop();
            
               
            int index = leftToright ? i :size - i - 1; //now placed the items from the front node in zigzag pattern in the ans , this will be done using index 
            ans[index] = frontNode->data;

            if(frontNode->left) //agar front node ka left non null hai toh push in queue 
                q.push(frontNode->left);
            if(frontNode->right) // agar front node ka right non null hai toh push in queue
                q.push(frontNode->right);
        }

        //Direction Change
        leftToright = !leftToright;

        for (auto i :ans)
        {
            result.push_back(i);
        }
        
        
    }

    return result;
    

    
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    vector<int> res = ZigZag(root);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}