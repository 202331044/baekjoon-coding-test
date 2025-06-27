#include "iostream"
#include "vector"
#include "queue"
#include "utility"

using namespace std;

int bfs(vector<vector<int>>& vec, queue<pair<int, int>>& que, int n, int m, int result)
{
	vector<vector<bool>> visited(n, vector<bool>(m));
	vector<vector<int>> cnt(n, vector<int>(m));
	pair<int, int> current = que.front();

	int r, c, tr, tc;
	int max = 0, res = 0;

	int dx[4] = {-1, 1, 0,0};
	int dy[4] = { 0, 0, -1, 1 };

	while (!que.empty())
	{
		current = que.front();

		r = current.first;
		c = current.second;

		if (visited[r][c] == false && vec[r][c] == 1)
		{
			visited[r][c] = true;
			res++;
			for (int i = 0; i < 4; i++)
			{
				tr = dx[i] + r;
				tc = dy[i] + c;

				if (tr >= 0 && tr < n && tc >= 0 && tc < m)
				{
					if (visited[tr][tc] == false && vec[tr][tc] == 0)
					{
						que.push({ tr, tc });
						
						cnt[tr][tc] = cnt[r][c] + 1;
						vec[tr][tc] = 1;
						if (max < cnt[tr][tc])
							max = cnt[tr][tc];
					}
				}
			}
		}
		que.pop();
	}

	if (res == result)
		return max;
	else
		return -1;
}

int main()
{
	int m, n, tmp;
	cin >> m >> n;

	int result = m * n;
	vector<vector<int>> vec(n);
	queue<pair<int, int>> que;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			vec[i].push_back(tmp);

			if (tmp == 1)
				que.push({ i, j });
			else if (tmp == -1)
				result--;
		}
	}

	if (que.size() == result)
		cout << 0;
	else
		cout << bfs(vec, que, n, m, result);
	
	return 0;
}
