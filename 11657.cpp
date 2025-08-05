#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int INF = 1e9;

bool bellmanFord(vector<tuple<int, int, int>>& root, vector<long long>& distance, int& n)
{
	distance[1] = 0;

	for (int i = 0; i < n; ++i)
	{
		for (auto r : root)
		{
			int u = get<0>(r);
			int v = get<1>(r);
			int w = get<2>(r);

			if (distance[u] != INF && distance[u] + w < distance[v])
				distance[v] = distance[u] + w;
		}
	}

	for (auto r : root)
	{
		int u = get<0>(r);
		int v = get<1>(r);
		int w = get<2>(r);

		if (distance[u] != INF && distance[u] + w < distance[v])
			return false;
	}

	return true;
}
int main()
{
	vector<tuple<int, int, int>> root;
	vector<long long> distance;
	
	int n, m;
	int u, v, w;
	
	cin >> n >> m;
	
	distance.assign(n + 1, INF);

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		root.push_back({ u, v, w });
	}

	bool result = bellmanFord(root, distance, n);

	if (result == false)
		cout << - 1;
	else
	{	
		for (int j = 2; j <= n; j++)
		{
			if (distance[j] >= INF)
				cout << -1 << "\n";
			else
				cout << distance[j] << "\n";
		}
	}

	return 0;
}
