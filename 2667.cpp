#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

int cnt = 0;

void bfs(vector<vector<bool>>& visited, vector<vector<int>>& vec, int n, int r, int c)
{
	if (visited[r][c] == true || vec[r][c] == 0)
		return;

	visited[r][c] = true;
	cnt++;

	if(r < n-1)
		bfs(visited, vec, n, r+1, c);
	if (r > 0)
		bfs(visited, vec, n, r - 1, c);
	if(c < n-1)
		bfs(visited, vec, n, r, c + 1);
	if (c > 0)
		bfs(visited, vec, n, r, c - 1);
}
int main()
{
	int n;
	string str;

	cin >> n;

	vector<vector<int>> vec(n);
	vector<vector<bool>> visited(n, vector<bool>(n));
	vector<int> result;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (char c : str)
			vec[i].push_back(c - '0');
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (vec[r][c] == 1)
			{
				bfs(visited, vec, n, r, c);

				if (cnt > 0)
					result.push_back(cnt);
				cnt = 0;
			}
		}
	}
	
	sort(result.begin(), result.end());

	cout << result.size() <<"\n";

	for (int& num : result)
		cout << num << "\n";

	return 0;
}
