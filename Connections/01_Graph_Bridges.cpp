#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int parent, vector<int> &visited, vector<int> &insertTime, vector<int> &lowestTime, int &timer, vector<int> adj[])
{
    visited[i] = 1;
    insertTime[i] = lowestTime[i] = timer++;
    for (int x : adj[i])
    {
        if (x == parent)
        {
            continue;
        }

        if (!visited[x])
        {
            dfs(x, i, visited, insertTime, lowestTime, timer, adj);
            lowestTime[i] = min(lowestTime[i], lowestTime[x]);
            if (lowestTime[x] > insertTime[i])
            {
                cout << i << " " << x << endl;
            }
        }
        else
        {
            lowestTime[i] = min(lowestTime[i], insertTime[x]);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> insertTime(V, -1);
    vector<int> lowestTime(V, -1);
    vector<int> visited(V, 0);
    int timer = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, visited, insertTime, lowestTime, timer, adj);
        }
    }

    return 0;
}