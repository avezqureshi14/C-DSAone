#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// the meaning of i = neighbours , aaju baju wale
// Agar apna visited true hai aur apun kisike parent bhi nahi hai , toh zaroor cycle present hai

bool isCyclic(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto i : adjList[frontNode])
        {
            if (visited[i] == true && i != parent[frontNode])
            {
                return true;
            }
            else if (visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
                //    i ka visited true
                parent[i] = frontNode;
                //    i ka parent frontNode
            }
        }
    }

    return false;
}
// vertex : no. of nodes
// edges : nodes
string CycleDetection(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all component of a graph
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            bool ans = isCyclic(adjList, visited, i);
            if (ans == true)
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
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(1, 4));
    string s = CycleDetection(5, edges);
    cout << s;

    return 0;
}