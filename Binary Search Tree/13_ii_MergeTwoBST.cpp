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

// Time Complexity O(n+m)
// Space Complexity O(h1+h2)

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
            cout << temp->data << " ";

            if (temp->left) // agar temp ka left hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(temp->left);
            }

            if (temp->right) // agar temp ka right hai toh bache hue hamare tree ke elements ko queue meh push karo
            {
                q.push(temp->right);
            }
        }
    }
}

void BSTtoSortedDLL(Node *root, Node *head)
{
    // base case
    if (root == NULL)
    {
        return ;
    }

    BSTtoSortedDLL(root->right, head);

    root->right = head;

    if (head != NULL)
    {
        head->left = root;
    }

    head = root;

    BSTtoSortedDLL(root->left, head);
}

Node *mergedLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    { 
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNode(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

Node *SortedLLToBST(Node *&head, int n)
{
    // basecase
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    Node *left = SortedLLToBST(head, n / 2);
    Node *root = head;

    root->left = left;

    head = head->right;

    root->right = SortedLLToBST(head, n - n / 2 - 1);
    return root;
}

Node *MergeBST(Node *root1, Node *root2)
{

    // STEP 1 Converted BST into Sorted DLL Inplace
    Node *head1 = NULL;
    BSTtoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    BSTtoSortedDLL(root2, head2);
    head2->left = NULL;

    // Step 2 Merge two Linked List
    Node *head = mergedLinkedList(head1, head2);

    // Step 3 Convert SLL into BST
    return SortedLLToBST(head, countNode(head));
}

int main()
{
    Node *root1 = NULL;
    root1 = buildTree(root1);
    Node *root2 = NULL;
    root2 = buildTree(root2);

    Node *root3;
    root3 = MergeBST(root1,root2);
    LevelOrderTraversal(root3);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 11 -1 -1 -1 -1