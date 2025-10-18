#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<int> vertex(MAX + 1, 1);

int dfs(int u, vector<vector<int>>& tree, vector<bool>& visited)
{
	for (auto v : tree[u])
	{
		if (visited[v] == false)
		{
			visited[v] = true;
			vertex[u] += dfs(v, tree, visited);
		}
	}

	return vertex[u];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<vector<int>> tree(MAX);
	vector<bool> visited(MAX, false);
	int n, r, q;
	int u, v;
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	visited[r] = true;
	dfs(r, tree, visited);

	for (int j = 0; j < q; ++j)
	{
		cin >> u;
		cout << vertex[u] << "\n";
	}
	return 0;
}
