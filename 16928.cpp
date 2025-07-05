#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int bfs(vector<int>& vec, int n, int m)
{
	vector<int> count(101);
	queue<int> que;

	que.push(1);
	
	while (!que.empty())
	{
		int current = que.front();

		for (int i = 1; i < 7; ++i)
		{
			int next = current + i;

			if (next <= 100)
			{
				if (vec[next] != -1)
					next = vec[next];
				if (count[next] == 0)
				{
					que.push(next);
					count[next] = count[current] + 1;
				}
			}
		}

		que.pop();
	}
	return count[100];
}
int main()
{
	int n, m;
	int x, y, u, v;
	vector<int> vec(101, -1);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vec[x] = y;
	}

	for (int j = 0; j < m; j++)
	{
		cin >> u >> v;
		vec[u] = v;
	}

	cout << bfs(vec, n, m);

	return 0;
}
