#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int curr, vector<vector<int>>& vec, vector<bool>& visited, vector<vector<int>>& dp)
{
	if (visited[curr]) return;
	visited[curr] = true;

	for (auto next : vec[curr])
	{
		if (visited[next]) continue;
		dfs(next, vec, visited, dp);
		dp[curr][0] += min(dp[next][1], dp[next][0]);
		dp[curr][1] += max(dp[next][0], 1);
	}
}

int main()
{
	int n, u, v;
	cin >> n;

	int result = n;
	vector<bool> visited(n + 1, false);
	vector<vector<int>> vec(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int j = 1; j <= n; ++j)
		dp[j][0] = 1;

	dfs(1, vec, visited, dp);
	cout << min(dp[1][0], dp[1][1]);

	return 0;
}
