#include <iostream>
#include <vector>

using namespace std;
vector<int> vec(1000);

int dp(vector<vector<int>>& arr, int left, int right, bool isTurn)
{
	if (left > right) return 0;
	if (arr[left][right] != -1) return arr[left][right];

	if (isTurn)
		return arr[left][right] = max(vec[left] + dp(arr, left + 1, right, false), vec[right] + dp(arr, left, right - 1, false));
	else
		return arr[left][right] = min(dp(arr, left + 1, right, true), dp(arr, left, right - 1, true));
}

int main()
{
	int t, n, tmp;
	cin >> t;
	while (t--)
	{
		cin >> n;

		vector<vector<int>> arr(n, vector<int>(n, -1));
		
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			vec[i] = tmp;
		}

		dp(arr, 0, n - 1, true);

		cout << arr[0][n - 1] << "\n";
	}

	return 0;
}
