#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int u, v;
	int edges;
	int r = 0, k = 0;
	vector<pair<int, int>> vec;
	cin >> n;
	vector<vector<bool>> visited(n + 1, vector<bool>(n+1, false));
	edges = (n * (n - 1)) / 2;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v;
		visited[u][v] = true;
		visited[v][u] = true;
	}
	
	if (edges <= 2 * (n - 1))
	{
		k = edges - (n - 1);
		r = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (visited[i][j])
					continue;
				vec.push_back({ i, j });
				visited[i][j] = visited[j][i] = true;
			}
		}
	}
	else
	{
		r = 2;
		for (int j = 2; j <= n; ++j)
		{
			if (visited[1][j])
				continue;
			vec.push_back({ 1, j });
			visited[1][j] = visited[j][1] = true;
			k++;
		}
	}

	cout << k << "\n" << r << "\n";
	for (auto node : vec)
		cout << node.first << " " << node.second << "\n";

	return 0;
}
