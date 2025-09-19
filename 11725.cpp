#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	const int MAX = 100000;
	int n;
	int a, b;
	vector<vector<int>> tree(MAX+1);
	vector<int> parent(MAX + 1);
	vector<bool> visited(MAX+1, false);

	cin >> n;

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	queue<int> que;
	que.push(1);
	visited[1] = true;

	while (!que.empty())
	{
		int curr = que.front();
		que.pop();

		for (int next : tree[curr])
		{
			if (visited[next] == true)
				continue;
			parent[next] = curr;
			visited[next] = true;
			que.push(next);
		}
	}

	for (int i = 2; i <= n; ++i)
		cout << parent[i] << "\n";

	return 0;
}
