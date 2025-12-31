#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

const int INF = 1e9;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, m;
	int s, e;

	cin >> n >> t >> m;
	cin >> s >> e;

	queue<tuple<int, int, int>> path;
	vector<int> dp(n + 1, INF), pre(n + 1, INF);
	dp[s] = pre[s] = 0;

	int u, v, w;
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> u >> v >> w;
			path.push({ u, v, w });
		}

		while(!path.empty())
		{
			auto [a, b, d] = path.front();
			path.pop();
			dp[b] = min(dp[b], pre[a] + d);
			dp[a] = min(dp[a], pre[b] + d);
		}
		pre = dp;
	}

	int result = dp[e] == INF ? -1 : dp[e];
	cout << result;

	return 0;
}
