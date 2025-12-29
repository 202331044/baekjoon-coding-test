#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int u, v, k;
	vector<vector<pii>> graph(N + 1);
	vector<int> indeg(N + 1);
	vector<vector<int>> dp(N + 1, vector<int>(N+1, 0));

	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> k;
		graph[v].push_back({ u, k });
		indeg[u]++;
	}

	queue<int> que;

	for (int i = 1; i <= N; ++i)
	{
		if (indeg[i] == 0)
		{
			que.push(i);
			dp[i][i] = 1;
		}		
	}

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		for (auto [next, cnt]: graph[cur])
		{
			for (int i = 1; i <= N; ++i)
			{
				if(dp[cur][i] > 0)
					dp[next][i] += dp[cur][i] * cnt;
			}

			if (--indeg[next] == 0)
				que.push(next);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (dp[N][i] != 0)
			cout << i << " " << dp[N][i] << "\n";
	}

	return 0;
}
