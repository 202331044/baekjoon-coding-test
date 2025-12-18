#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int main()
{
	int n;
	cin >> n;

	vector<vector<int>> dp(1 << n, vector<int>(n, INF));
	vector<vector<int>> W(n, vector<int>(n));
	dp[1][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> W[i][j];
	}

	for (int k = 1; k < (1 << n); ++k)
	{
		for (int l = 1; l < n; ++l)
		{
			if (k & (1 << l))
				continue;

			for (int m = 0; m < n; ++m)
			{
				if (W[m][l] != 0 && (k & (1 << m)) && dp[k][m] != INF)
				{
					dp[k | (1 << l)][l] = min(dp[k | (1 << l)][l], dp[k][m] + W[m][l]);
				}
			}	
		}
	}

	int answer = INF;
	for (int i = 1; i < n; ++i)
	{
		if(W[i][0] != 0)
			answer = min(answer, dp[(1 << n) - 1][i] + W[i][0]);
	}

	cout << answer;
	return 0;
}
