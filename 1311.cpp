#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 200000;
int func(int n, vector<vector<int>>& vec)
{
	vector<vector<int>> dp(20, vector<int>(1 << 21, MAX));

	for (int i = 0; i < n; ++i)
		dp[0][1 << (i + 1)] = vec[0][i];

	for (int r = 1; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			for(int idx = 0; idx < (1 << (n + 1)); ++idx)
			{
				if (idx & (1 << (c + 1)))
					continue;
				dp[r][idx|(1 << (c + 1))] = min(dp[r][idx | (1 << (c + 1))], (vec[r][c] + dp[r-1][idx]));
			}
		}
	}
	return dp[n - 1][(1 << (n + 1)) - 2];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> vec[i][j];
	}
	
	cout << func(n, vec);
	return 0;
}
