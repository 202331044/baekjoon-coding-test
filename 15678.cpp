#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	int n, d;
	long long maxVal = -1e9;
	cin >> n >> d;
	vector<long long> vec(n + 1, 0);
	vector<long long> dp(n + 1, 0);
	priority_queue<pair<long long, int>> pq;

	for (int i = 1; i <= n; ++i)
		cin >> vec[i];
		
	pq.push({ vec[1], 1});
	for (int j = 2; j <= n; ++j)
	{
		while (!pq.empty() && pq.top().second < j - d)
			pq.pop();
		
		dp[j] = max(pq.top().first + vec[j], pq.top().first);
		dp[j] = max(dp[j], vec[j]);
		maxVal = dp[j] > maxVal ? dp[j] : maxVal;
		pq.push({ max(pq.top().first + vec[j], vec[j]), j});
	}

	cout << maxVal;

	return 0;
}
