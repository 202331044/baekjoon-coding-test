#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	vector<int> path(n + 1);

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		path[i] = i - 1;

		if (i % 2 == 0)
		{
			if (dp[i / 2] + 1 < dp[i])
			{
				dp[i] = dp[i / 2] + 1;
				path[i] = i / 2;
			}
		}

		if (i % 3 == 0)
		{
			if (dp[i / 3] + 1 < dp[i])
			{
				dp[i] = dp[i / 3] + 1;
				path[i] = i / 3;
			}
		}
	}
	
	cout << dp[n] << "\n";

	int num = n;
	while (num)
	{
		cout << num << " ";
		num = path[num];
	}
	
	return 0;
}
