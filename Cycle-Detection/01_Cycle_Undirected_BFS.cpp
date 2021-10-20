#include <bits/stdc++.h>
using namespace std;

bool BFSCycle(vector<int> adj[], vector<bool> &visited, int i)
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    visited[i] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int par = q.front().second;
        q.pop();

        for (int z : adj[x])
        {
            if (!visited[z])
            {
                q.push({z, x});
                visited[z] = 1;
            }
            else if (z != par)
            {
                return true;
            }
        }
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
            if (BFSCycle(adj, visited, i))
            {
                cout << "cycle" << endl;
            }
        }
    }
    cout << "No Cycle" << endl;
    return 0;
}