#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, list<int>> adjList;
void prepareAdjList(vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
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
    prepareAdjList(edges);
    printAdjList();
    return 0;
}