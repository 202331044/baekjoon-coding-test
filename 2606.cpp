#include "iostream"
#include "queue"
#include "vector"

using namespace std;

int main()
{
	
	int n, m;
	int u, v, now = 1;
	int cnt = 0;

	cin >> n >> m;

	vector<bool> visited(n + 1);
	vector<vector<int>> vec(n + 1);
	queue<int> que;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	visited[now] = true;
	que.push(now);

	while (!que.empty())
	{	
		now = que.front();
		for (int& node : vec[now])
		{
			if (!visited[node])
			{
				visited[node] = true;
				cnt++;
				que.push(node);
			}
		}
		que.pop();
	}

	cout << cnt;
	return 0;
}
