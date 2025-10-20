#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;

vector<vector<int>> vec(MAX);
vector<vector<int>> dp(MAX, vector<int>(2, 0));

void dfs(int city, vector<vector<int>>& vec, vector<bool>& visited)
{
	if (visited[city]) return;
	visited[city] = true;

	for (auto next : vec[city])
	{
		if (visited[next]) continue;
		dfs(next, vec, visited);

		dp[city][0] += dp[next][1];
		dp[city][1] += max(dp[next][0], dp[next][1]);
	}
}

int main()
{
	int n, u, v;
	vector<bool> visited(MAX, false);
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> dp[i][0];
			
	for (int j = 0; j < n - 1; ++j)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	dfs(1, vec, visited);

	int result = 0;
	for (int k = 1; k <= n; ++k)
	{
		for (int l = 0; l < 2; ++l)
		{
			if (result < dp[k][l])
				result = dp[k][l];
		}
	}

	cout << result;
	return 0;
}
