#include <bits/stdc++.h>
using namespace std;
void dfs(int x, stack<int> &st, vector<int> &visited, vector<int> adj[])
{
    visited[x] = 1;
    for (auto it : adj[x])
    {
        if (!visited[it])
        {
            dfs(it, st, visited, adj);
        }
    }
    st.push(x);
}

void revDfs(int x, vector<int> &visited, vector<int> transpose[])
{
    cout << x << " ";
    visited[x] = 1;
    for (auto it : transpose[x])
    {
        if (!visited[it])
        {
            revDfs(it, visited, transpose);
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
    }

    // Stack of Topological sort
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, st, visited, adj);
        }
    }

    // Transposing the Graph
    vector<int> transpose[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    // Kosaraju Algo
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        if (!visited[x])
        {
            cout << "SCC: ";
            revDfs(x, visited, transpose);
            cout << endl;
        }
    }

    return 0;
}

/*
5 5
0 1
1 2
2 0
1 3
3 4
*/