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

class ListNode
{
public:
    int data;
    ListNode *next;
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

int LCA(Node *root, int val1, int val2)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data > val1 && root->data > val2)
    {
        return LCA(root->left, val1, val2);
    }

    if (root->data < val1 && root->data < val2)
    {
        return LCA(root->right, val1, val2);
    }

    return root->data;
}

int maximum(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    int res = root->data;
    int left = maximum(root->left);
    int right = maximum(root->right);

    if (res < left)
    {
        res = left;
    }
    if (res < right)
    {
        res = right;
    }

    return res;
}

bool isValid(Node *root, long minVal, long maxVal)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data <= minVal || root->data >= maxVal)
    {
        return false;
    }

    return isValid(root->left, minVal, root->data) &&
           isValid(root->right, root->data, maxVal);
}

bool isValid(Node *root)
{
    return isValid(root, INT_MIN, INT_MAX);
}

Node *LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
    return root;
}

int Size(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Size(root->left);
    int right = Size(root->right);

    int ans = left + right + 1;

    return ans;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int height = max(left, right) + 1;

    return height;
}

int Diameter(Node *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Diameter(root->left, diameter);
    int right = Diameter(root->right, diameter);

    diameter = max(diameter, (left + right));

    return max(left, right) + 1;
}

int Diameter(Node *root)
{
    int diameter = 0;
    Diameter(root, diameter);
    return diameter;
}

int Bal(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = Bal(root->left);
    if (leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = Bal(root->right);

    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight > 1))
    {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool Balanced(Node *root)
{
    int res = Bal(root);
    if (res == -1)
    {
        return false;
    }
    return true;
}

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
    {
        return true;
    }

    return false;
}

vector<int> VerticalOrderTraversal(Node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int vd = temp.second.first;
        int lvl = temp.second.second;

        nodes[vd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(vd - 1, lvl + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(vd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

vector<int> TopView(Node *root)
{
    map<int, int> topNode;
    queue<pair<Node *, int>> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int vd = temp.second;

        if (topNode.find(vd) == topNode.end())
        {
            topNode[vd] = frontNode->data;
        }
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, vd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, vd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int KdanesMaximumSubarraySum(int arr[], int n)
{
    int final = INT_MIN, curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr = curr + arr[i];
        if (curr > final)
        {
            final = curr;
        }
        if (curr < 0)
        {
            curr = 0;
        }
    }

    return final;
}

int RemoveDuplicates(int arr[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int findWater(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int left_max = 0;
    int right_max = 0;
    int water = 0;
    while (low <= high)
    {
        if (arr[low] < arr[high])
        {
            if (arr[low] > left_max)
            {
                left_max = arr[low];
            }
            else
            {
                water += left_max - arr[low];
            }
            low++;
        }
        else
        {
            if (arr[high] > right_max)
            {
                right_max = arr[high];
            }
            else
            {
                water += right_max - arr[high];
            }
            high--;
        }
    }
    return water;
}

vector<int> TwoSum(vector<int> nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            ans.push_back(map[target - nums[i]]);
            ans.push_back(i);
        }
        map[nums[i]] = i;
    }
    return ans;
}

vector<vector<int>> FourSum(vector<int> nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (nums.empty())
    {
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target2 = target - nums[j] - nums[i];
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                int TwoSum = nums[left] + nums[right];
                if (target2 > TwoSum)
                {
                    right--;
                }
                else if (target2 < TwoSum)
                {
                    left++;
                }
                else
                {
                    vector<int> quad(4, 0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    ans.push_back(quad);

                    while (left < right && nums[left] == quad[2])
                    {
                        ++left;
                    }
                    while (left < right && nums[right] == quad[3])
                    {
                        --right;
                    }
                }
            }
            while (j + 1 < n && nums[j + 1] == nums[j])
            {
                ++j;
            }
        }

        while (i + 1 < n && nums[i + 1] == nums[i])
        {
            ++i;
        }
    }
    return ans;
}

void PushAfter(ListNode *prev_node, int new_data)
{
    ListNode *new_node = new ListNode();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void PushAtEnd(ListNode **head_ref, int new_data)
{
    ListNode *new_node = new ListNode();
    new_node->data = new_data;
    ListNode *last = (*head_ref);

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->next = NULL;
}

void deleteNode(ListNode **head_ref, int key)
{
    ListNode *temp1 = *head_ref;
    ListNode *temp2 = NULL;
    if (temp1 != NULL && temp1->data == key)
    {
        *head_ref = temp1->next;
        delete (temp1);
    }

    while (temp1->next != NULL && temp1->data != key)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete (temp1);
}

ListNode *Midpoint(ListNode *head_ref)
{
    ListNode *fast = head_ref;
    ListNode *slow = head_ref;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->next;
}

ListNode *Reverse(ListNode *head_ref)
{
    ListNode *curr = Midpoint(head_ref);
    ListNode *prev = NULL;

    while (curr != NULL)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool isPalindrome(ListNode *head_ref)
{
    ListNode *curr = (head_ref);
    ListNode *last = Reverse(head_ref);

    while (last != NULL)
    {
        if (curr->data != last->data)
        {
            return false;
        }
        curr = curr->next;
        last = last->next;
    }

    return true;
}

ListNode *Detect(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return slow;
}
bool Detecting(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int DetectFirstNode(ListNode *head)
{
    ListNode *meet = Detect(head);
    ListNode *start = head;
    while (meet != start)
    {
        meet = meet->next;
        start = start->next;
    }
    return start->data;
}
void removeCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow->next = NULL;
}

ListNode *MergeTwoLinkedLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    ListNode *result = l1;

    if (l1->data > l2->data)
    {
        swap(l1, l2);
    }

    while (l1 != NULL && l2 != NULL)
    {
        ListNode *temp = NULL;

        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }

        temp->next = l2;
        swap(l1, l2);
    }

    return result;
}

int MaximumSubaraaySum(int arr[], int n)
{
    int curr_sum = 0;
    int maxi = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if (curr_sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (map.find(curr_sum) != map.end())
            {
                maxi = max(maxi, i - map[curr_sum]);
            }
            else
            {
                map[curr_sum] = i;
            }
        }
    }

    return maxi;
}

string reverseString(string s)
{
    int n = s.length();
    stack<char> cs;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        cs.push(ch);
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        char ch = cs.top();
        ans.push_back(ch);
        cs.pop();
    }
    cout << "The reversed version is " << ans;
    return ans;
}

void StackDelete(stack<int> &inputStack, int count, int n)
{
    if (count == n / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();
    StackDelete(inputStack, count + 1, n);
    inputStack.push(num);
}

void StackDelete(stack<int> &inputStack, int size)
{
    int count = 0;
    StackDelete(inputStack, count, size);
}

void print(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

bool isValidParenthesis(string s)
{
    int n = s.length();
    stack<char> stk;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '{' || ch == '[' || ch == '(')
        {
            stk.push(ch);
        }
        else
        {
            if (!stk.empty())
            {
                char top = stk.top();
                if (top == '{' && ch == '}' || top == '[' && ch == ']' || top == '(' && ch == ')')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (stk.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Input Stack must be by address
void SolveInsertAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    SolveInsertAtBottom(myStack, x);

    myStack.push(num);
}

stack<int> InsertAtBottom(stack<int> &myStack, int x)
{
    SolveInsertAtBottom(myStack, x);
    return myStack;
}

void ReverseStack(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }

    int num = stk.top();
    stk.pop();
    ReverseStack(stk);

    SolveInsertAtBottom(stk, num);
}

void SortInserted(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    SortInserted(s, x);
    s.push(num);
}

void SortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int store = s.top();
    s.pop();
    SortStack(s);

    SortInserted(s, store);
}

bool isRedundant(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            s.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool Redundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        Redundant = false;
                    }
                    s.pop();
                }
                if (Redundant == true)
                {
                    return true;
                }
                s.pop();
            }
        }
    }

    return false;
}

int MinCostToMakeString(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }

        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

// see
// understand
// dry run
// write on paper
// write on ide
// derive in words

int main()
{
    string s = "}}}{}{}}}";
    int res = MinCostToMakeString(s);
    cout << "The Minimum Cost to make a String is " << res << endl;

    return 0;
}