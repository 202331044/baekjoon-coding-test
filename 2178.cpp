#include "iostream"
#include "vector"
#include "queue"
#include "utility"

using namespace std;
int bfs(vector<vector<bool>>& vec, vector<vector<bool>>& visited, int n, int m, int r, int c)
{
	queue <pair<int,int>> que;
	vector<vector<int>> cnt(n, vector<int>(m));

	que.push({ r, c });
	cnt[r][c] = 1;

	int dr[4] = {1, -1, 0, 0};
	int dc[4] = { 0, 0, 1, -1 };
	int newr, newc;

	while (!que.empty())
	{
		pair<int, int> pos = que.front();

		if (pos.first == n - 1 && pos.second == m - 1)
			break;

		if (vec[pos.first][pos.second] == true && visited[pos.first][pos.second] == false)
		{
			visited[pos.first][pos.second] = true;

			for (int i = 0; i < 4; i++)
			{
				newr = dr[i] + pos.first;
				newc = dc[i] + pos.second;
				if (newr >= 0 && newr < n && newc >= 0 && newc < m)
				{
					que.push({ newr, newc });
					if (cnt[newr][newc] != 0)
						cnt[newr][newc] = min(cnt[pos.first][pos.second] + 1, cnt[newr][newc]);
					else
						cnt[newr][newc] = cnt[pos.first][pos.second] + 1;
				}	
			}
		}
		que.pop();
	}

	return cnt[n - 1][m - 1];
}

int main()
{
	int n, m;
	string str;

	cin >> n >> m;

	vector<vector<bool>> vec(n);
	vector<vector<bool>> visited(n, vector<bool>(m));

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (char c : str)
			vec[i].push_back(c - '0');
	}

	cout << bfs(vec, visited, n, m, 0, 0);

	return 0;
}
