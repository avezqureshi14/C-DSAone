#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Union(int a[], int b[], int n, int m)
{
    unordered_set<int>set;
    for (int i = 0; i < n; i++)
    {
        set.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        set.insert(b[i]);
    }
    cout<<"The size of union of elements is "<<set.size()<<endl;
    
    
}


int main()
{
    int a[] = {5,5,7,9,7};
    int n =sizeof(a)/sizeof(a[0]);
    int b[] = {6,5,3,9,7};
    int m =sizeof(b)/sizeof(b[0]);
    Union(a,b,n,m);
    return 0;
}