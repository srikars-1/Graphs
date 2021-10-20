// Function to determine if adj can be coloured with at most M colours such
// that no two adjacent vertices of adj are coloured with same colour.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool adj[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && adj[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int V, bool adj[101][101])
{
    if (node == V)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, adj, V, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, V, adj))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool adj[101][101], int m, int V)
{
    int color[V] = {0};
    if (solve(0, color, m, V, adj))
    {
        return true;
    }
    return false;
}