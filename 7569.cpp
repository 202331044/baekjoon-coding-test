#include "iostream"
#include "vector"
#include "queue"
#include "tuple"

using namespace std;

int bfs(int h, int n, int m, int total, vector<vector<vector<int>>>& vec, queue<tuple<int, int, int>>& que)
{
	vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(n, vector<bool>(m)));
	vector<vector<vector<int>>> count(h, vector<vector<int>>(n, vector<int>(m, 0)));

	int max = 0;
	int cnt = 0;
	int dr[6] = {-1, 1, 0, 0, 0, 0};
	int dc[6] = { 0, 0, -1, 1, 0, 0 };
	int dh[6] = { 0, 0, 0, 0, -1, 1 };

	while (!que.empty())
	{
		tuple<int, int, int> pos = que.front();

		int th = get<0>(pos);
		int tr = get<1>(pos);
		int tc = get<2>(pos);

		cnt++;

		for (int i = 0; i < 6; i++)
		{
			int nh = th + dh[i];
			int nr = tr + dr[i];
			int nc = tc + dc[i];

			if (nh >= 0 && nh < h && nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (visited[nh][nr][nc] == false && vec[nh][nr][nc] == 0)
				{
					que.push({ nh, nr, nc });

					count[nh][nr][nc] = count[th][tr][tc] + 1;
					visited[nh][nr][nc] = true;

					if (max < count[nh][nr][nc])
						max = count[nh][nr][nc];
				}
			}
		}
		que.pop();
	}

	if (cnt == total)
		return max;
	else
		return -1;
}

int main()
{
	int m, n, h;
	int total = 0;
	int cnt = 0;

	cin >> m >> n >> h;

	total = m * n * h;

	vector<vector<vector<int>>> vec(h, vector<vector<int>>(n, vector<int>(m)));
	queue<tuple<int, int, int>> que;

	for (int i = 0; i < h; i++)
	{
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				cin >> vec[i][r][c];
				if (vec[i][r][c] == 1)
				{
					que.push({ i, r, c });
					cnt++;
				}
				else if (vec[i][r][c] == -1)
					total--;
			}
				
		}
	}
	
	if (total == cnt)
		cout << 0;
	else
		cout << bfs(h, n, m, total, vec, que);
	return 0;
}
