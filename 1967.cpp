#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int edge_node = 0;
int maxLen = 0;

void bfs(vector<vector<pair<int, int>>>& vec, vector<bool>& visited, int start)
{
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		int node = now.first;
		int dist = now.second;

		for(auto next: vec[node])
		{
			int next_node = next.first;
			int next_dist = next.second;

			if (visited[next_node] == false)
			{
				visited[next_node] = true;
				q.push({ next_node, dist + next_dist });

				if (maxLen < dist + next_dist)
				{
					maxLen = dist + next_dist;
					edge_node = next_node;
				}
			}
		}
	}
}

int main()
{
	vector<vector<pair<int, int>>> vec(10001);
	vector<bool> visited(10001);
	int n;
	int a, b, d;

	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b >> d;

		vec[a].push_back({b, d });
		vec[b].push_back({ a, d });
	}

	bfs(vec, visited, 1);
	fill(visited.begin(), visited.end(), false);
	bfs(vec, visited, edge_node);

	cout << maxLen << endl;

	return 0;
}
