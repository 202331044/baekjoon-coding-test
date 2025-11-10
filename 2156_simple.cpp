#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n + 1);
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; ++i)
		cin >> vec[i + 1];

	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];
	
	for (int i = 3; i <= n; ++i)
		dp[i] = max(max(dp[i - 1], dp[i - 3] + vec[i - 1] + vec[i]), dp[i - 2] + vec[i]);

	cout << dp[n];

	return 0;
}
