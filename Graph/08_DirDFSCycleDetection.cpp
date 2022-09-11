// agar node ka visited true hai aur sath meh node ka dfs visited bhi true hai toh bhai cycle toh present hai
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isCycleDFS(int nodes, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList)
{
    visited[nodes] = true;
    dfsVisited[nodes] = true;

    for (auto i : adjList[nodes])
    {
        if (visited[i] == 0)
        {
            bool cycleDetected = isCycleDFS(i, visited, dfsVisited, adjList);
            if (cycleDetected == true)
            {
                return true;
            }
        }
        else if (dfsVisited[i] == 1)
        {
            return true;
        }
    }

    dfsVisited[nodes] = false;
    return false;
}

string detectCycleInDirectedGraph(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        // This is a Directed Graph
        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // call dfs for all components
    for (int i = 1; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            bool cycleDetected = isCycleDFS(i, visited, dfsVisited, adjList);
            if (cycleDetected == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 7));
    edges.push_back(make_pair(3, 8));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(4, 5));
    edges.push_back(make_pair(5, 6));
    edges.push_back(make_pair(6, 4));
    edges.push_back(make_pair(8, 7));
    string s = detectCycleInDirectedGraph(8, edges);
    cout << s;
    return 0;
}