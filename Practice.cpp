#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Anagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int n = s.length();
    int m = t.length();
    if (n != m)
    {
        cout << "No";
    }

    s == t ? cout << "Yes" : cout << "No";
}

// Works if no duplicates are present
int Func(int arr[], int n)
{
    vector<int> odd;            // O(n)
    vector<int> even;           // O(n)
    for (int i = 0; i < n; i++) // O(N)
    {
        if (i % 2 == 0)
        {
            even.push_back(arr[i]);
        }
        else
        {
            odd.push_back(arr[i]);
        }
    }

    sort(even.begin(), even.end()); // O(NlogN)
    sort(odd.begin(), odd.end());   // O(NlogN)
    int evenLarg, oddLarg;
    for (int i = 0; i < even.size(); i++) // O(n)
    {
        int k;
        if (i == even.size() - 2)
        {
            evenLarg = even[i];
            k = even.size() - 1;
        }
        if (evenLarg == k)
        {
            int j = 0;
            for (int i = n - 1; i >= 0; i++)
            {
                if (i != j)
                {
                    evenLarg = even[j];
                }
            }
        }
    }
    for (int i = 0; i < odd.size(); i++) // O(n)
    {
        if (odd.size() == 2)
        {
            oddLarg = odd[0];
        }

        else
        {
            oddLarg = odd[1];
        }
    }

    int sum = evenLarg + oddLarg;

    for (auto i : even)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : odd)
    {
        cout << i << " ";
    }
    cout << endl;
    return sum;
}

// int  Productsmallpair(int arr[], int sum){
//     int n  = sizeof(arr)/sizeof(arr[0]);
//     for (int i = 0; i < n; i++)
//     {

//     }

// }

int intOperation(int a, int b, int c)
{
    int ans = 0;
    switch (c)
    {
    case 1:
        ans = (a + b);
        break;
    case 2:
        ans = (a - b);
        break;
    case 3:
        ans = (a * b);
        break;
    case 4:
        ans = (a / b);
        break;
    }

    return ans;
}

int Sum(int a, int b)
{
    int sum = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            sum = sum + i;
        }
    }

    return sum;
}

int Password(char str[], int n)
{
    if (n < 4)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0')
        {
            cout << "First digit" << endl;
            return 0;
        }

        if (str[i] == ' ' || str[i] == '/')
        {
            cout << "Oblique and space" << endl;

            return 0;
        }
    }
    // How to check whether at least one of all number is present
    for (char i = 'A'; i < 'Z'; i++)
    {
        if (str[i] != i)
        {
            cout << "Capital" << endl;

            return 0;
        }
    }
    for (char i = '0'; i < '9'; i++)
    {
        if (str[i] != i)
        {
            cout << "First number" << endl;

            return 0;
        }
    }

    return 1;
}

// How to know which element has occured maximum in a unordered map

int ReplaceChar(string &s)
{
    int n = s.length();
    int count = 0;
    int maxi = 0;
    sort(s.begin(), s.end());
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
    }

    // int i = 0;
    // for (int j = 0; j < n; j++)
    // {
    //     count++;
    //     maxi = max(maxi,count);
    //     if (s[i] != s[j])
    //     {
    //         i = j;
    //         count = 0;
    //     }

    // }

    return maxi;
}

int webAccess(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    int k;
    cout << "Enter the value of k " << endl;
    cin >> k;
    int ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (k == i)
        {
            ans = nums[i];
        }
    }
    return ans;
}

int SumDivisor(int num)
{
    int sum = 0;
    for (int i = 1; i < INT_MAX; i++)
    {
        if (num % i == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

vector<int> MaxNum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    vector<int> ans;
    for(auto i : nums){
    ans.push_back(i);
    }

    return ans;
}

int main()
{
    // int m, n, sum = 0, totalSum = 0;
    // cout << "Enter the value of n" << endl;
    // cin >> n;
    // cout << endl;
    // cout << "ENter the value of m " << endl;
    // cin >> m;

    // for (int i = 1; i < n + 1; i++)
    // {
    //     if (i % m != 0)
    //     {
    //         sum = sum + i;
    //     }

    //     totalSum = totalSum + i;
    // }

    // int dis = totalSum - sum;
    // int ans = sum - dis;
    // cout << ans;

    // int arr[] = {2,3,4,5,7,8,9};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // cout << Func(arr, n);

    // cout<<intOperation(3,2,1);
    // cout<<Sum(3,5);

    // char str[] = {'a','A','1','_','6','7'};
    // int n = sizeof(str) / sizeof(str[0]);
    // cout<<Password(str,n);

    // string s = "abbbmbbbaaaa";
    // int res = ReplaceChar(s);
    // cout<<res;

    // vector<int> nums;
    // nums.push_back(74);
    // nums.push_back(85);
    // nums.push_back(102);
    // nums.push_back(99);
    // nums.push_back(101);
    // nums.push_back(56);
    // nums.push_back(84);
    // int res = webAccess(nums);
    // cout << res;

    // cout << SumDivisor(36);

    vector<int>nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(5);
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(4);
    for(auto i : MaxNum(nums)){
        cout<<i<<" ";
    }
    return 0;
}