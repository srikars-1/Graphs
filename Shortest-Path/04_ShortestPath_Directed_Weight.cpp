#include <bits/stdc++.h>
using namespace std;

void DFS(vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st, int i)
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (!visited[x.first])
        {
            DFS(adj, visited, st, x.first);
        }
    }
    st.push(i);
}

void shortestPath(vector<pair<int, int>> adj[], vector<int> &distance, int V, int source)
{
    vector<int> visited(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(adj, visited, st, i);
        }
    }

    distance[source] = 0;

    while (!st.empty())
    {
        int x = st.top();
        st.pop();

        if (distance[x] != INT_MAX)
        {
            for (auto z : adj[x])
            {
                if (distance[z.first] > distance[x] + z.second);
                {
                    distance[z.first] = distance[x] + z.second;
                }
            }
        }
    }
}

int main()
{
    int V;
    vector<pair<int, int>> adj[V];
    int source;
    vector<int> distance(V, INT_MAX);

    shortestPath(adj, distance, V, source);

    return 0;
}