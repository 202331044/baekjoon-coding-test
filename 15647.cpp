#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int root, vector<vector<pair<int ,int>>>& vec, vector<int>& child, vector<long long>& dp, vector<bool>& visited)
{
	for (auto next : vec[root])
	{
		int next_node = next.first;
		int next_d = next.second;
		if (visited[next_node]) continue;

		visited[next_node] = true;
		dfs(next_node, vec, child, dp, visited);

		child[root] += child[next_node];
		dp[root] += dp[next_node] + (child[next_node] * next_d);
	}
}

void shortest_path(int n, vector<long long>& path, vector<vector<pair<int, int>>>& vec, vector<int>& child, vector<long long>& dp, vector<bool>& visited)
{
	queue<int> que;
	que.push(1);
	visited[1] = true;
	while (!que.empty())
	{
		int root = que.front();
		que.pop();

		for (auto next : vec[root])
		{
			int next_node = next.first;
			int next_d = next.second;
			if (visited[next_node]) continue;
			visited[next_node] = true;

			long long num = path[root] - (dp[next_node] + (next_d * child[next_node]));
			path[next_node] = dp[next_node] + num + ((n - child[next_node]) * next_d);
			que.push(next_node);
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, u, v, d;
	cin >> n;
	vector<vector<pair<int, int>>> vec(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v >> d;
		vec[u].push_back({ v, d });
		vec[v].push_back({ u, d });
	}

	vector<int> child(n + 1, 1);
	vector<long long> dp(n + 1, 0);
	vector<bool> visited(n + 1, false);
	visited[1] = true;

	dfs(1, vec, child, dp, visited);

	vector<long long> path(n + 1);
	visited.assign(n + 1, false);
	path[1] = dp[1];

	shortest_path(n, path, vec, child, dp, visited);

	for (int i = 1; i <= n; ++i)
		cout << path[i] << "\n";

	return 0;
}
