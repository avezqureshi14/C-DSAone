#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Prepare(unordered_map<int,list<int>>&adjList, vector<pair<int,int>>&edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }
    
}

bool dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adjList){
    visited[node] = 1;
    dfsvisited[node] = 1;

    for(auto i : adjList[node]){
        if (visited[i] == 0)
        {
            bool ans = dfs(i,visited,dfsvisited,adjList);
            if (ans == true)
            {
                return true;
            }
            
        }
        else if(dfsvisited[i] == true){
            return true;
        }
        
    }

    dfsvisited[node] = false;
    return false;    
}

string DFSCycle(int vertex, vector<pair<int,int>>&edges){
    unordered_map<int,list<int>>adjList;
    Prepare(adjList,edges);
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsvisited;
    for (int i = 1; i <= vertex; i++)
    {
        if (visited[i] == 0)
        {
            bool ans = dfs(i,visited,dfsvisited,adjList);
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
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 7));
    edges.push_back(make_pair(3, 8));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(4, 5));
    edges.push_back(make_pair(5, 6));
    edges.push_back(make_pair(6, 4));
    edges.push_back(make_pair(8, 7));
    string s = DFSCycle(8, edges);
    cout << s;
    return 0;
}