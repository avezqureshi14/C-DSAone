#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// N = number of vertex
// E = number of edges
//Time Complexity : O(N+E)
//Space Complexity : O(N+E)

unordered_map<int, list<int>> adj;

//In implementation we had defined adjList outside the function here we are passing it as a argument because we want to fill it and use 
//and the u and v (Edges) which were passing in prev case are passed here as pair of both 
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
        int frontNode = q.front();
        q.pop();

        // store frontnode in ans
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for (auto i : adjList[frontNode])
        {
            if (visited[i]==0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
//vertex : no. of nodes
//edges : nodes
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all component of a graph
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i]==0)
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{

    return 0;
}