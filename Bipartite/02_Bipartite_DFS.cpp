#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<int> adj[], vector<int> &visited, int i)
{
    for (int x : adj[i])
    {
        if (visited[x] == -1)
        {
            visited[x] = 1 - visited[i];
            if (!DFS(adj, visited, x))
            {
                return false;
            }
        }
        else if (visited[x] == visited[i])
        {
            return false;
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
            visited[i] = 1;
            if (!DFS(adj, visited, i))
            {
                cout << "Not Bipartite";
            }
        }
    }
    cout << "Bipartite";

    return 0;
}
