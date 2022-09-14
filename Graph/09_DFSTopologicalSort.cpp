#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void topSort(int nodes, vector<bool> &visited, stack<int> &s, unordered_map<int, set<int>> &adjList)
{
    visited[nodes] = 1;
    for (auto i : adjList[nodes])
    {
        if (visited[i] == 0)
        {
            topSort(i, visited, s, adjList);
        }
    }
    // important
    // as you will be returning from the recursive call we have to put elements in the stack

    s.push(nodes);
}

vector<int> topoLogicalSort(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
    }
    // call dfs topological sort util function for all components
    vector<bool> visited(vertex); // map changed to vector to overcome TLE
    stack<int> s;
    for (int i = 1; i < vertex; i++) // remember to change initial value of as per the nodes in the graph are starting from
    {
        if (visited[i] == 0)
        {
            topSort(i, visited, s, adjList);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop(); // remember, Never forget to remove the value from the stack whenever you have stored it somewhere        }
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(3, 5));
    edges.push_back(make_pair(5, 4));
    cout << "Topological Sort using DFS" << endl;
    for (auto i : topoLogicalSort(5, edges))
    {
        cout << i << " ";
    }

    return 0;
}