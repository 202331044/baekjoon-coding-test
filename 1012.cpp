#include "iostream"
#include "vector"
using namespace std;

bool check = false;
void dfs(vector<vector<bool>>& vec, vector<vector<bool>>& visited, int r, int c, int m, int n)
{
	if (vec[r][c] == false || visited[r][c] == true)
		return;

	visited[r][c] = true;
	check = true;

	if (r > 0)
		dfs(vec, visited, r - 1, c, m, n);
	if (c > 0)
		dfs(vec, visited, r, c-1, m, n);
	if (r < m - 1)
		dfs(vec, visited, r + 1, c, m, n);
	if (c <  n - 1)
		dfs(vec, visited, r, c + 1, m, n);
}
int main()
{
	int t, m, n, k;
	int x, y;
	vector<int> result;

	cin >> t;

	while (t--)
	{
		cin >> m >> n >> k;

		vector<vector<bool>> vec(m, vector<bool>(n));
		vector<vector<bool>> visited(m, vector<bool>(n));
		int cnt = 0;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			vec[x][y] = true;
		}

		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				dfs(vec, visited, j, k, m, n);
				if (check == true)
					cnt++;
				check = false;
			}
		}
		result.push_back(cnt);
	}

	for (int res : result)
		cout << res << "\n";

	return 0;
}
