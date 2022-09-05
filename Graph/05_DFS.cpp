#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjList, vector<int> component)
{
    component.push_back(node);
    visited[node] = true;

    // har connected node ke liye recursive call

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int vertex, int e, vector<vector<int>> &edges)
{
    // prepare adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[1][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    //for all nodes call dfs if not visited
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
}
int main()
{

    return 0;
}