#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<array<int, 3>> vec(N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cin >> vec[i][j];
	}

	array<int, 3> dp, prev;
	prev = vec[0];
	for (int i = 1; i < N; ++i)
	{
		dp[0] = vec[i][0] + min(prev[1], prev[2]);
		dp[1] = vec[i][1] + min(prev[0], prev[2]);
		dp[2] = vec[i][2] + min(prev[0], prev[1]);
		prev = dp;
	}

	int result = min({ dp[0], dp[1], dp[2]});
	cout << result;
	return 0;
}
