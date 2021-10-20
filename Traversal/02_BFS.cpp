#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], vector<bool> &visited, vector<int> &ans, int i)
{
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ans.push_back(x);

		for (int z : adj[x])
		{
			if (!visited[z])
			{
				q.push(z);
				visited[z] = 1;
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
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			BFS(adj, visited, ans, i);
		}
	}
	return 0;
}