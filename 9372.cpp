#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& vec)
{
	int answer = 0;
	queue<int> que;
	vector<bool> visited(1001, false);
	que.push(1);
	visited[1] = true;

	while (!que.empty())
	{
		int curr = que.front();
		que.pop();

		for (auto next : vec[curr])
		{
			if (visited[next] == false)
			{
				que.push(next);
				visited[next] = true;
				answer++;
			}
		}
	}
	return answer;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		int a, b;
		cin >> n >> m;
		vector<vector<int>> vec(n + 1);

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		cout << bfs(vec) << "\n";
	}
	return 0;
}
