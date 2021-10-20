#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<int> adj[], vector<bool> &visited, vector<bool> &DFSvisited, int i)
{
    visited[i] = true;
    DFSvisited[i] = true;
    for (int x : adj[i])
    {
        if (!visited[x])
        {
            DFS(adj, visited, DFSvisited, x);
        }
        else if(DFSvisited[x])
        {
            return true;
        }
    }
    DFSvisited[i] = false;
    return false;
}

int main()
{
    int V;
    vector<int> adj[V];

    vector<bool> visited(V, false), dfs(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if(DFS(adj, visited, dfs, i)) cout << "CYCLE FOUND";
        }
    }
    cout << "CYCLE NOT FOUND";
    return 0;
}