#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdj(unordered_map<int,set<int>> &adjList,vector<pair<int, int>> &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
     // adjList[insideMap].insert(insideSet);
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    
}

void bfs(unordered_map<int,set<int>> &adjList , unordered_map<int,bool> &visited , vector<int> &ans , int node){
    
}

vector<int> BFS(int vertex, vector<pair<int, int>>edges){
    unordered_map<int,set<int>>adjList;
    vector<int>ans;
    vector<pair<int,bool>>visited;

    prepareAdj(adjList,edges);
}

int main()
{
    
    return 0;
}