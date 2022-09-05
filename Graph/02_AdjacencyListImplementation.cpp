#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void prepareAdjList(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v (linking)
        adjList[u].push_back(v);

        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges "<<endl;
    cin>>m;
    Graph g;
    for (int i = 0; i < m; i++)
    {
        int u,v; 
        cin>>u>>v;
        
        g.prepareAdjList(u,v,0);
    }
    
    g.printAdjList();
    return 0;
}