#include "iostream"
#include "vector"
#include "queue"

using namespace std;

bool visited[1001][1001][2] = { false };

struct Container
{
	bool broken;
	int cnt;
	int r;
	int c;
};

int bfs(vector<vector<bool>>& vec, int n, int m)
{
	queue<Container> que;

	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	que.push({0, 1, 1, 1});
	int r = 1, c = 1;
	int broken, cnt;
	int nr, nc;

	visited[r][c][0] = true;

	while (!que.empty())
	{
		
		Container con = que.front();

		r = con.r;
		c = con.c;
		broken = con.broken;
		cnt = con.cnt;

		if (r == n && c == m)
			return cnt;

		for (int i = 0; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];

			if (nr >= 1 && nr <= n && nc >= 1 && nc <= m)
			{
				if (broken == false)
				{
					if (vec[nr][nc] == 0 && visited[nr][nc][0] == false)
					{
						visited[nr][nc][0] = true;
						que.push({ 0, cnt + 1, nr ,nc });
					}
					else if(vec[nr][nc] == 1 && visited[nr][nc][1] == false)
					{
						visited[nr][nc][1] = true;
						que.push({ 1, cnt + 1, nr, nc });
					}					
				}
				else
				{
					if (vec[nr][nc] == 0 && visited[nr][nc][1] == false)
					{
						visited[nr][nc][1] = true;
						que.push({ 1, cnt + 1, nr, nc });
					}
				}
			}
		}
		que.pop();
	}
	return -1;
}

int main()
{
	int n, m;
	char c;

	cin >> n >> m;

	vector<vector<bool>> vec(n + 1, vector<bool>(m + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			vec[i][j] = c - '0';
		}
	}

	cout << bfs(vec, n, m);

	return 0;
}
