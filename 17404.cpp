#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int solveFixedFirst(int firstColor, int N, vector<array<int, 3>>& cost)
{
	array<int, 3> dp, prev;
	prev.fill(INF);
	prev[firstColor] = cost[0][firstColor];

	for (int i = 1; i < N; ++i)
	{
		dp[0] = cost[i][0] + min(prev[1], prev[2]);
		dp[1] = cost[i][1] + min(prev[0], prev[2]);
		dp[2] = cost[i][2] + min(prev[0], prev[1]);
		prev = dp;
	}
	
	int result = INF;
	for (int i = 0; i < 3; ++i)
	{
		if (firstColor == i)
			continue;
		result = min(result, dp[i]);
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<array<int, 3>> cost(N);
	for (int i = 0; i < N; ++i)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	int result = INF;
	for (int cnt = 0; cnt < 3; ++cnt)
		result = min(result, solveFixedFirst(cnt, N, cost));

	cout << result;

	return 0;
}
