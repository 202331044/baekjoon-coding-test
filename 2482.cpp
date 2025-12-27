#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MAX = 1000000003;

int main()
{
	int N, K;
	cin >> N >> K;
	
	vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
	for (int i = 0; i <= N; ++i)
		dp[i][0] = 1;
	dp[1][1] = 1;
	
	if (K == 1)
		cout << N;
	else
	{
		for (int i = 2; i <= N; ++i)
		{
			for (int j = 1; j <= K; ++j)
			{
				if (i <= j)
					break;
				dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MAX;
			}
		}
		cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MAX;
	}
	
	return 0;
}
