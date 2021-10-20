#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int i)
{
    if (i == parent[i])
    {
        return i;
    }
    return parent[i] = findParent(parent, parent[i]);
}

// Union is called only when parents are not same
void Union(vector<int> &parent, vector<int> &rank, int u, int v)
{
    int u = findParent(parent, u);
    int v = findParent(parent, v);
    if(rank[u]>rank[v])
    {
        parent[v] = u;
    }
    else if(rank[u]<rank[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int main()
{
    int V;
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
}