#include "iostream"
#include "vector"
#include "stack"
using namespace std;

void dfs(vector<vector<int>>& vec, vector<bool>& visited, stack<int>& result, int next)
{
	if (vec[next].size() == 0)
	{
		result.push(next);
		return;
	}
	for (int node : vec[next])
	{
		if (visited[node] == false)
		{
			visited[node] = true;
			dfs(vec, visited, result, node);
		}
	}
	result.push(next);
}
int main()
{
	int n, m;
	int s, e;
	cin >> n >> m;

	vector<vector<int>> vec(n+1, vector<int>());
	vector<int> degree(n + 1);
	vector<bool> visited(n + 1);
	stack<int> result;

	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		vec[s].push_back(e);
		degree[e]++;
	}

	for (int j = 1; j <= n; ++j)
	{
		if (degree[j] == 0 && visited[j] == false)
		{
			visited[j] = true;
			dfs(vec, visited, result, j);
		}
		
	}
	
	while (!result.empty())
	{
		cout << result.top() << " ";
		result.pop();
	}
		
	return 0;
}
