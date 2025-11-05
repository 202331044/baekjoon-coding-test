#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int cnt = 1;
bool isDrain(vector<vector<int>>& vec, int x, int y, int len)
{
	for (int j = y; j < y + len; ++j)
	{
		for (int i = x; i < x + len; ++i)
		{
			if (vec[j][i] != 0)
				return false;
		}
	}
	return true;
}

void dc(vector<vector<int>>& vec, int x, int y, int len)
{
	if (len <= 2)
	{
		for (int i = y; i < y + len; ++i)
		{
			for (int j = x; j < x + len; ++j)
			{
				if (vec[i][j] == 0)
					vec[i][j] = cnt;
			}
		}
		cnt++;
		return;
	}

	int half = len / 2;
	if (isDrain(vec, x, y, half))
		vec[y + half - 1][x + half - 1] = cnt;
	if (isDrain(vec, x + half, y, len / 2))
		vec[y + half - 1][x + half] = cnt;
	if (isDrain(vec, x, y + half, len / 2))
		vec[y + half][x + half - 1] = cnt;
	if (isDrain(vec, x + half, y + half, len / 2))
		vec[y + half][x + half] = cnt;
	cnt++;

	dc(vec, x, y, half);
	dc(vec, x + half, y, half);
	dc(vec, x, y + half, half);
	dc(vec, x + half, y + half, half);
}

int main()
{
	int k, x, y;
	cin >> k;
	cin >> x >> y;
	int n = pow(2, k);
	vector<vector<int>> vec(n, vector<int>(n, 0));
	vec[n - y][x - 1] = -1;

	dc(vec, 0, 0, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << vec[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
