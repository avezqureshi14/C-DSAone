#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, list<int>> adjList;

void Prepare(int vertex, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < vertex; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

queue<int> q;

vector<int> BFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int,bool>visited;
    for(auto i : adjList){
        if(visited[i] == 0){
            
        }
    }    
}

int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(5, 0));
    edges.push_back(make_pair(4, 0));
    edges.push_back(make_pair(5, 2));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 3));
    Prepare(6, edges);
    print();
    return 0;
}