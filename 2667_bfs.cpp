#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
#include "string"

using namespace std;

int bfs(vector<vector<bool>>& vec, vector<vector<bool>>& visited, int r, int c, int n)
{
	int cnt = 0;
	queue<pair<int ,int>> que;
	que.push({ r, c });

	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	while (!que.empty())
	{
		pair<int, int> pos = que.front();

		if (vec[pos.first][pos.second] == true && visited[pos.first][pos.second] == false)
		{
			visited[pos.first][pos.second] = true;
			cnt++;

			for (int i = 0; i < 4; i++)
			{
				int tr = pos.first + dr[i];
				int tc = pos.second + dc[i];
				if(tr >= 0 && tr < n && tc >= 0 && tc < n)
					que.push({ tr, tc});
			}
		}

		que.pop();
	}

	return cnt;
}

int main()
{
	int n;
	vector<int> result;
	string str;
	cin >> n;

	vector<vector<bool>> vec(n);
	vector<vector<bool>> visited(n, vector<bool>(n));

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (char c : str)
			vec[i].push_back(c - '0');
	}

	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < n; k++)
		{
			if (vec[j][k] == true && visited[j][k] == false)
			{
				int cnt = bfs(vec, visited, j, k, n);
				if (cnt != 0)
					result.push_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";

	for (int res : result)
		cout << res << "\n";

	return 0;
}
