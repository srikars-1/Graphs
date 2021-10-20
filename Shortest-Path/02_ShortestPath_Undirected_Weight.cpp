#include <bits/stdc++.h>
using namespace std;


void Dijkstra(vector<pair<int, int>> adj[], vector<int> &distance, int source)
{
    // min-heap ; pair {xDist,from}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;                                              

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();

        for (auto z : adj[x])
        {
            if (distance[z.first] > distance[x] + z.second)
            {
                distance[z.first] = distance[x] + z.second;
                pq.push({distance[z.first], z.first});
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V];

    int a, b, wt;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    int source;
    vector<int> distance(V, INT_MAX);
    Dijkstra(adj, distance, source);

    return 0;
}