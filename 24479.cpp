#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> result(100001, 0);
int idx = 1;

void dfs(vector<vector<int>> &vec, vector<bool> &visited, int r)
{
	visited[r] = true;
	result[r] = idx;
	idx++;
	int size = vec[r].size();
	for (auto node: vec[r])
	{
		if (!visited[node])
			dfs(vec, visited, node);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m, r;
	int u, v;
	vector<vector<int>> vec(100001);
	vector<bool> visited(100001);
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	
	for (int j = 0; j < vec.size(); j++)
		sort(vec[j].begin(), vec[j].end());

	dfs(vec, visited, r);

	for (int k = 1; k <= n; k++)
		cout << result[k] << "\n";

	return 0;
}
