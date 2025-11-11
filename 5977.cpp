#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> vec(n + 1, 0);
	vector<long long> psum(n + 1, 0);
	vector<long long> dp(n + 1, 0);
	deque<pair<int, long long>> dq;

	for (int i = 1; i <= n; ++i)
	{
		cin >> vec[i];
		psum[i] = psum[i - 1] + vec[i];
	}

	dq.push_back({ 0, 0 });
	for (int j = 1; j <= n; ++j)
	{
		while (!dq.empty())
		{
			if (dq.front().first < j - k)
				dq.pop_front();
			else
				break;
		}

		dp[j] = dq.front().second + psum[j];
		dp[j] = max(dp[j], dp[j - 1]);

		long long num = dp[j - 1] - psum[j];
		while (!dq.empty() && dq.back().second <= num)
			dq.pop_back();

		dq.push_back({ j, num });
	}
	
	cout << dp[n];
}
