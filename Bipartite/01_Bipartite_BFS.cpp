#include <bits/stdc++.h>
using namespace std;

bool BFS(vector<int> adj[], vector<int> &visited, int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int z : adj[x])
        {
            if (visited[z] == -1)
            {
                q.push(z);
                visited[z] = 1 - visited[x];
            }
            else if (visited[z] == visited[x])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int V;
    vector<int> adj[V];

    vector<int> visited(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == -1)
        {
            if (!BFS(adj, visited, i))
            {
                cout << "Not Bipartite";
            }
        }
    }
    cout << "Bipartite";

    return 0;
}
