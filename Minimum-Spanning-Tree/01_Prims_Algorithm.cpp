#include <bits/stdc++.h>
using namespace std;

void Prims(vector<pair<int, int>> adj[], vector<pair<int, int>> ans[], int V)
{
    vector<int> parent(V, -1); // Contains parent of i-th index
    vector<int> weight(V, INT_MAX); // Weight between i and parent[i]
    vector<bool> inMST(V, false); // Inclded in MST or not

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // has minimum weight as first element

    weight[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        inMST[x] = true;

        for (auto z : adj[x])
        {
            if (inMST[z.first] == false && weight[z.first] > z.second)
            {
                parent[z.first] = x;
                weight[z.first] = z.second;
                pq.push({z.second, z.first});
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        ans[i].push_back({parent[i], weight[i]});
        ans[parent[i]].push_back({i, weight[i]});
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

    vector<pair<int, int>> ans[V];
    Prims(adj, ans, V);

    for (int i = 0; i < V; i++)
    {
        cout << i << "->";
        for (auto x : ans[i])
        {
            cout << "(" << x.first << ", " << x.second << ") " << "-> ";
        }
        cout << "\b\b\b" << endl;
    }

    return 0;
}