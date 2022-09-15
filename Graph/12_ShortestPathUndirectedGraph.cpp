#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>shortestPath(vector<pair<int,int>> &edges, int vertex, int start , int end){
    //create adjacency list
    unordered_map<int,list<int>>adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    //do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int>q;
    q.push(start);
    parent[start] = -1;
    visited[start] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for(auto i : adjList[frontNode]){
            if (visited[i] == 0)
            {
                visited[i] = true;
                parent[i] = frontNode;
                q.push(i);
            }
            
        }
    }
    
    vector<int>ans;
    int currentNode = end;
    ans.push_back(end);
    while (currentNode != start)
    {
        currentNode = parent[currentNode]; //finding parents of our currentNode
        ans.push_back(currentNode);
    }

    reverse(ans.begin(),ans.end());
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
    for(auto i : shortestPath(edges,5,0,3)){
        cout<<i<<" -> ";
    }

    return 0;
}