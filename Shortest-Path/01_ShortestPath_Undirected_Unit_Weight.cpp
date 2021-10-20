#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], vector<int> &distance, int V, int source)
{
    queue<int> q;
    distance[source] = 0;
    q.push(source);

    while (q.empty() == false)
    {
        int x = q.front();
        q.pop();

        for (auto z : adj[x])
        {
            if (distance[z] > distance[x]+1)
            {
                distance[z] = distance[x] + 1;
                q.push(z);
            }
        }
    }
}

int main()
{
    int V;
    vector<int> adj[V];

    vector<int> distance(V, INT_MAX);
    int source;

    BFS(adj, distance, V, source);

    return 0;
}