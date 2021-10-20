#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], vector<bool> &visited, stack<int> &st, int i)
{
    visited[i] = true;
    for (int x : adj[i])
    {
        if (!visited[x])
        {
            DFS(adj, visited, st, x);
        }
    }
    st.push(i);
}

int main()
{
    int V;
    vector<int> adj[V];

    vector<bool> visited(V, false);
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(adj, visited, st, i);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return 0;
}