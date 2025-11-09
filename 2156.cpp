#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<vector<int>> dp(n, vector <int>(3, 0));
	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	dp[0][1] = vec[0];
	dp[0][2] = vec[0];

	for (int j = 1; j < n; ++j)
	{
		dp[j][0] = max(max(dp[j-1][0], dp[j - 1][2]), dp[j - 1][1]);
		dp[j][1] = dp[j - 1][0] + vec[j];
		dp[j][2] = dp[j - 1][1] + vec[j];
	}

	int result = 0;
	result = max(dp[n - 1][0], dp[n - 1][1]);
	result = max(result, dp[n - 1][2]);

	cout << result;

	return 0;
}
