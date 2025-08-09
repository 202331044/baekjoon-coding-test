#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>>& vec, int n)
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (vec[i][k] != INF && vec[k][j] != INF)
				{
					if (vec[i][k] + vec[k][j] < vec[i][j])
						vec[i][j] = vec[i][k] + vec[k][j];
				}
			}
		}
	}
}
int main()
{
	int n, m;
	int a, b, c;
	vector<vector<int>> vec(101, vector<int>(101, INF));
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		if (vec[a][b] > c)
			vec[a][b] = c;
	}

	for (int j = 0; j <= n; ++j)
		vec[j][j] = 0;

	floyd_warshall(vec, n);

	for (int k = 1; k <= n; ++k)
	{
		for (int l = 1; l <= n; ++l)
		{
			if (vec[k][l] >= INF)
				cout << 0 << " ";
			else
				cout << vec[k][l] << " ";
		}	
		cout << "\n";
	}
	return 0;
}
