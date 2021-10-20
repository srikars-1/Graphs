#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], vector<bool> &visited, vector<int> &ans, int i)
{
    visited[i] = true;
    ans.push_back(i);
    for (int x : adj[i])
    {
        if (!visited[x])
        {
            DFS(adj, visited, ans, x);
        }
    }
}

int main()
{
    int V;
    vector<int> adj[V];

    vector<bool> visited(V, false);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(adj, visited, ans, i);
        }
    }
    return 0;
}