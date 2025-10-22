#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& vec, vector<vector<int>>& dp, vector<bool>& visited)
{
	for (auto next : vec[node])
	{
		if (visited[next] == false)
		{
			visited[next] = true;
			dfs(next, vec, dp, visited);
			dp[node][0] += dp[next][1];
			dp[node][1] += max(dp[next][0], dp[next][1]);
		}
	}
}

void trace(int node, int parent, bool include, vector<vector<int>>& vec, vector<vector<int>>& dp, vector<int>& result)
{
	if (include)
	{
		result.push_back(node);
		for (auto next : vec[node])
		{
			if (next == parent) continue;
			trace(next, node, false, vec, dp, result);
		}
	}
	else
	{
		for (auto next : vec[node])
		{
			if (next == parent) continue;
			if(dp[next][0] < dp[next][1])
				trace(next, node, false, vec, dp, result);
			else
				trace(next, node, true, vec, dp, result);
		}
	}
}

int main()
{

	int n, w;
	int u, v;
	cin >> n;
	vector<vector<int>> vec(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	vector<bool> visited(n + 1, false);

	for (int i = 1; i <= n; ++i)
	{
		cin >> w;
		dp[i][0] = w;
	}

	for (int j = 0; j < n - 1; ++j)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	visited[1] = true;
	dfs(1, vec, dp, visited);
	cout << max(dp[1][0], dp[1][1]) << "\n";

	vector<int> result;
	if (dp[1][0] < dp[1][1])
		trace(1, 0, false, vec, dp, result);
	else
		trace(1, 0, true, vec, dp, result);

	sort(result.begin(), result.end());
	for (auto res : result)
		cout << res << " ";

	return 0;
}
