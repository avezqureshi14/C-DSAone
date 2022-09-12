#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool BFSCycleDetectionInDirectedGraph(int vertex, vector<pair<int, int>> &edges)
{
    // create adj list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(vertex);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < vertex; i++) // if nodes are starting from zero then take care of i
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    int count = 0; // if count is equal to the no. of nodes present in the Graph then the cycle is not present
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // increment in count
        count++;

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for (auto i : adjList[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (count == vertex)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    vector<pair<int, int>> edges;
    // please checkout whether easch edge has been placed same phas
    edges.push_back(make_pair(5, 0));
    edges.push_back(make_pair(4, 0));
    edges.push_back(make_pair(5, 2));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 3));
    cout << "Topological Sort using DFS" << endl;
    bool ans = BFSCycleDetectionInDirectedGraph(6, edges);
    if (ans == true)
    {
        cout << "The Cycle is Present" << endl;
    }
    else
    {
        cout << "Cycle is not Present " << endl;
    }

    return 0;
}