#include <bits/stdc++.h>
using namespace std;

bool DFSCycle(vector<int> adj[], vector<bool> &visited, int i, int parent)
{
    visited[i] = true;
    for (int x : adj[i])
    {
        if (!visited[x])
        {
            if (DFSCycle(adj, visited, x, i))
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
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
            if (DFSCycle(adj, visited, i, -1))
            {
                cout << "cycle" << endl;
            };
        }
    }
    cout << "No Cycle" << endl;
    return 0;
}