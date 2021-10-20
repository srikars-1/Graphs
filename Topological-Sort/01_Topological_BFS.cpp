#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int V, vector<int> &ans)
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto z : adj[i])
        {
            indegree[z]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (auto z : adj[x])
        {
            indegree[z]--;
            if (indegree[z] == 0)
            {
                q.push(z);
            }
        }
    }
}

int main()
{
    int V;
    vector<int> adj[V];

    vector<bool> visited(V, false);
    vector<int> ans;

    BFS(adj, V, ans);
    return 0;
}