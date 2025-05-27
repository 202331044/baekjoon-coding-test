#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<bool> visited(100001, false);
vector<int> result(100001, 0);
int cnt = 1;

void dfs(const vector<vector<int>> & vec, int r)
{
	visited[r] = true;
	result[r] = cnt;
	cnt++;
	for (auto& node : vec[r])
	{
		if (visited[node] == false)
			dfs(vec, node);
	}
}

int main()
{
	int n, m, r;
	int u, v;
	vector<vector<int>> vec(100001);
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	int size = vec.size();

	for (auto& nodes : vec)
		sort(nodes.begin(), nodes.end(), greater<>());

	dfs(vec, r);

	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";
	
	return 0;
}
