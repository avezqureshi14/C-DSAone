#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void PrePare(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << " ( " << j.first << "," << j.second << " ) ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = true;
        for (auto i : adjList[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void GetShortestPath(int src, vector<int> &distance, stack<int> &topo)
    {
        distance[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if(distance[top] != INT_MAX){
                for(auto i : adjList[top]){
                    if(distance[top] + i.second < distance[i.first]){
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.PrePare(0, 1, 5);
    g.PrePare(0, 2, 3);
    g.PrePare(1, 2, 2);
    g.PrePare(1, 3, 6);
    g.PrePare(2, 3, 7);
    g.PrePare(2, 4, 4);
    g.PrePare(2, 5, 2);
    g.PrePare(3, 4, -1);
    g.PrePare(4, 5, -2);

    g.printAdj();

    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> distance(n);
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }

    g.GetShortestPath(src,distance,s);
    cout<<"Answer is "<<endl;

    for (int i = 0; i < distance.size(); i++)
    {
        cout<<distance[i]<<" ";
    }cout<<endl;
     


    return 0;
}