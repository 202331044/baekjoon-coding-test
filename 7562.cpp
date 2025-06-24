#include "iostream"
#include "queue"
#include "utility"
#include "vector"

using namespace std;

int bfs(int cr, int cc, int dr, int dc, int l)
{
	int result = 0;

	vector<vector<bool>> visited(l, vector<bool>(l));
	vector<vector<int>> cnt(l, vector<int>(l));
	queue<pair<int, int>> que;

	int tr, tc;
	int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	visited[cr][cc] = true;
	que.push({ cr,cc });

	while (!que.empty())
	{
		pair<int, int> tmp = que.front();

		if (tmp.first == dr && tmp.second == dc)
			break;

		for (int i = 0; i < 8; i++)
		{
			tr = tmp.first + dx[i];
			tc = tmp.second + dy[i];
			if (tr >= 0 && tr < l && tc >= 0 && tc < l)
			{
				if (visited[tr][tc] == false)
				{
					visited[tr][tc] = true;
					cnt[tr][tc] = cnt[tmp.first][tmp.second] + 1;
					que.push({ tr, tc });
				}
			}
		}

		que.pop();
	}

	return cnt[dr][dc];
}

int main()
{
	int t, l, cr, cc, dr, dc;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> l;
		cin >> cr >> cc;
		cin >> dr >> dc;

		cout << bfs(cr, cc, dr, dc, l) << "\n";
	}

	return 0;
}
