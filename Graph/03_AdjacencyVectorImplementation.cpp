#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Love Babbar
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges){
    vector<int> ans[n];
    //ans array will store all adjacent corresponding nodes
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u); //comment this of it is directed graph
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        //for entering neighbours
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
        
    }

    return adj; 
    
    
} 
int main()
    
{
    //Striver
    // int n,m;
    // cin>>n>>m;
    // vector<int> adj[n+1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u,v;
    //     cin>>u>>v;

    //     adj[u].push_back(v);
    //     adj[v].push_back(u); //comment this of it is directed graph
    // }

     
    //Striver if weights are given
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt}); //comment this of it is directed graph
    }
    
    return 0;
}