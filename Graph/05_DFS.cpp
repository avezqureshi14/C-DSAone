#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, set<int>> adjList, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    // har connected node ke liye recursive call

    //Jab aaju baju wale ko bulate toh sirf ek ko lekhar aage badne ka 
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int vertex, vector<pair<int, int>> edges) //previously they gave us the pair of edges now they gave vector of edges
{
    // prepare adjList
    unordered_map<int, set<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    //for all nodes call dfs if not visited
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(3, 4));
    for (auto i : depthFirstSearch(4, edges))
    {
        for(auto j : i){
            cout<<j<<" ";
        }
            cout<<endl;
    }




    


    return 0;
}