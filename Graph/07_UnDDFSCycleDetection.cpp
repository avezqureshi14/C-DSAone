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

bool isCyclicDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node, int parent)
{
    visited[node] = 1;

    for (auto i : adjList[node])
    {
        if (visited[i] = 0) //check if visited is false, if yes move forward in if
        {
            //as this is a recursive call our answer will be coming from the last call 
            bool ans = isCyclicDFS(adjList, visited, i, node); //Now if our function has brought true from the last iteration then return true
            if (ans == true)
            {
                return true;
            }
        }
        else if (i != parent) //if above condition is not accepted it means visited is true and now if it is also not a parent of any node then cycle exists
        {
            return true;
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
            bool ans = isCyclicDFS(adjList, visited, i, -1);
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