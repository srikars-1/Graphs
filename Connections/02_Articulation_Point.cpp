#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int parent, vector<int> &visited, vector<int> &insertTime, vector<int> &lowestTime, int &timer, vector<int> adj[], vector<int> &isArticulation)
{
    visited[i] = 1;
    insertTime[i] = lowestTime[i] = timer++;
    int child = 0;

    for (int x : adj[i])
    {
        if (x == parent)
        {
            continue;
        }

        if (!visited[x])
        {
            dfs(x, i, visited, insertTime, lowestTime, timer, adj, isArticulation);
            lowestTime[i] = min(lowestTime[i], lowestTime[x]);
            child++;
            if (lowestTime[x] >= insertTime[i] && parent != -1)
            {
                isArticulation[i] = 1;
            }
        }

        else
        {
            lowestTime[i] = min(lowestTime[i], insertTime[x]);
        }

        if (parent == -1 && child > 1)
        {
            isArticulation[i] = 1;
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
    vector<int> isArticulation(V, 0);
    int timer = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, visited, insertTime, lowestTime, timer, adj, isArticulation);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (isArticulation[i] == 1)
        {
            cout << i << endl;
        }
    }

    return 0;
}