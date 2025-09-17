#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	const int MAX = 1e9;

	int a, b, c;
	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, MAX));
	vector<vector<int>> path(n + 1, vector<int>(n + 1, -1));

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		if (c < dist[a][b])
		{
			dist[a][b] = c;
			path[a][b] = b;
		}	
	}

	for (int j = 1; j <= n; ++j)
	{
		dist[j][j] = 0;
	}
		
	for (int k = 1; k <= n; ++k)
	{
		for (int r = 1; r <= n; ++r)
		{
			for (int c = 1; c <= n; ++c)
			{
				if (dist[r][k] + dist[k][c] < dist[r][c])
				{
					dist[r][c] = dist[r][k] + dist[k][c];
					path[r][c] = path[r][k];
				}
			}
		}
	}

	for (int j = 1; j <= n; ++j)
	{
		for (int l = 1; l <= n; ++l)
		{
			if (dist[j][l] == MAX)
				cout << 0 << " ";
			else
				cout << dist[j][l] << " ";
		}
		cout << "\n";
	}	

	for (int p = 1; p <= n; ++p)
	{
		for (int q = 1; q <= n; ++q)
		{
			if (p == q || path[p][q] == -1)
			{
				cout << 0 << "\n";
				continue;
			}

			vector<int> vec;
			int curr = p;
			vec.push_back(curr);

			while (curr != q)
			{
				vec.push_back(path[curr][q]);
				curr = path[curr][q];
			}

			int size = vec.size();
			cout << size << " ";
			for (int i = 0; i < size; ++i)
				cout << vec[i] << " ";
			cout << "\n";
		}
	}

	return 0;
}
