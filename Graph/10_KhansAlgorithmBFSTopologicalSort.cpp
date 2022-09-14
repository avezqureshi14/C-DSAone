#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> BFSTopologicalSort(int vertex, vector<pair<int, int>> &edges)
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
    vector<int> indegree(vertex); //jitne apne upar arrows hai utni apni indegree
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < vertex; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

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
    return ans;
}

int main()
{
    vector<pair<int, int>> edges;
    //please checkout whether easch edge has been placed same phas
    edges.push_back(make_pair(5,0));
    edges.push_back(make_pair(4,0));
    edges.push_back(make_pair(5,2));
    edges.push_back(make_pair(4,1));
    edges.push_back(make_pair(3,1));
    edges.push_back(make_pair(2,3));
    cout<<"Topological Sort using DFS"<<endl;
    for(auto i : BFSTopologicalSort(6,edges)){
        cout<<i<<" ";
    }
    return 0;
}