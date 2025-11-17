#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	int N, M, C, D;
	cin >> N >> M >> C >> D;
	
	vector<int> vec(N);
	for (int i = 0; i < N; ++i)
		cin >> vec[i];

	vector<vector<int>> dp(N, vector<int>(M + 1, 0));
	for (int j = 1; j <= M; ++j)
		dp[0][j] = M - abs(vec[0] - j);
		
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			int k;
			priority_queue<pair<int, int>> pq;
			for (k = j; k <= M; k += C)
			{
				while (!pq.empty() && pq.top().second < k - 2*D)
					pq.pop();
				pq.push({ dp[i-1][k], k});

				if (k - D <= 0)
					continue;

				dp[i][k - D] = pq.top().first + (M - abs(vec[i] - (k - D)));				
			}

			for (int t = k - D; t <= M; t += C)
			{
				if (t <= 0)
					continue;

				while (!pq.empty() && pq.top().second < t - D)
					pq.pop();
				dp[i][t] = pq.top().first + (M - abs(vec[i] - t));
			}
		}
	}

	int maxVal = -1e9;
	for (int i = 0; i <= M; ++i)
		maxVal = max(maxVal, dp[N - 1][i]);

	cout << maxVal;

	return 0;
}
