#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int a;
    int b;
    int wt;
    Node(int x, int y, int z) : a(x), b(y), wt(z) {}
};

bool cmp(Node &x, Node &y)
{
    return x.wt < y.wt;
}

int findParent(vector<int> &parent, int i)
{
    if (i == parent[i])
    {
        return i;
    }
    return parent[i] = findParent(parent, parent[i]);
}

void Union(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

void kruskals(vector<pair<int, int>> adj[], vector<Node> &edges, int V)
{
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    for (auto i : edges)
    {
        if (findParent(parent, i.a) != findParent(parent, i.b))
        {
            Union(parent, rank, i.a, i.b);
            adj[i.a].push_back({i.b, i.wt});
            adj[i.b].push_back({i.a, i.wt});
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Node> edges;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Node(a, b, c));
    }
    sort(edges.begin(), edges.end(), cmp);

    vector<pair<int, int>> ans[V];
    kruskals(ans, edges, V);
    
    for (int i = 0; i < V; i++)
    {
        cout << i << "->";
        for (auto x : ans[i])
        {
            cout << "(" << x.first << ", " << x.second << ") " << "-> ";
        }
        cout << endl;
    }
    
    return 0;
}

// 5 7
// 0 1 7
// 0 2 1
// 0 3 5
// 1 2 6
// 1 3 4
// 2 4 2
// 3 4 3