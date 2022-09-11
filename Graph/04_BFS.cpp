#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// N = number of vertex
// E = number of edges
// Time Complexity : O(N+E)
// Space Complexity : O(N+E)

//if you will use the list then of course you will find it in a sorted order or else order will be jumbled


// In implementation we had defined adjList outside the function here we are passing it as a argument because we want to fill it and use
// and the u and v (Edges) which were passing in prev case are passed here as pair of both
void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        // Save in frontnode
        int frontNode = q.front();
        q.pop();

        // Save frontnode in ans
        ans.push_back(frontNode);

        // Aaju baju wale ko bulao
        for (auto i : adjList[frontNode])
        {
            if (visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
// vertex : no. of nodes
// edges : nodes
vector<int> BFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all component of a graph
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}


int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(1, 4));
    for (auto i : BFS(5, edges))
    {
        cout << i << " ";
    }

    return 0;
}