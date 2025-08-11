#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>>& vec, vector<int>& dist, int v)
{
	
	for (int k = 1; k <= v; ++k)
	{
		for (int i = 1; i <= v; ++i)
		{
			for (int j = 1; j <= v; ++j)
			{
				if (vec[i][j] > vec[i][k] + vec[k][j])
					vec[i][j] = vec[i][k] + vec[k][j];
				if (i == j && vec[i][k] + vec[k][j] != 0)
				{
					if (dist[i] > vec[i][k] + vec[k][j])
						dist[i] = vec[i][k] + vec[k][j];
				}
			}
		}
	}
}
int main()
{

	int v, e;
	int a, b, c;
	int minVal = INF;

	cin >> v >> e;

	vector<vector<int>> vec(v + 1, vector<int>(v+1, INF));
	vector<int> dist(v + 1, INF);

	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b >> c;
		vec[a][b] = c;
	}

	for (int j = 0; j <= v; ++j)
		vec[j][j] = 0;

	floyd_warshall(vec, dist, v);

	for (int k = 1; k <= v; ++k)
	{
		if (minVal > dist[k])
			minVal = dist[k];
	}

	if (minVal != INF)
		cout << minVal;
	else
		cout << -1;

	return 0;
}
