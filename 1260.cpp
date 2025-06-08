#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

vector<bool> visited1(1001);
vector<bool> visited2(1001);

void dfs(vector<vector<int>>& vec, vector<int>& result, int & v)
{
	visited1[v] = true;
	result.push_back(v);
	for(int& node: vec[v])
	{
		if (visited1[node] == false)
			dfs(vec, result, node);
	}
}

void bfs(vector<vector<int>>& vec, vector<int>& result, int& v)
{
	queue<int> que;
	visited2[v] = true;
	que.push(v);
	result.push_back(v);
	while (!que.empty())
	{
		int tmp = que.front();
		for (int& node : vec[tmp])
		{
			if (visited2[node] == false)
			{
				visited2[node] = true;
				que.push(node);
				result.push_back(node);
			}
		}
		que.pop();
	}
}

int main()
{
	int n, m, v;
	int a, b;

	vector<vector<int>> vec(1001);
	vector<int> result1;
	vector<int> result2;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int j = 1; j <= n; j++)
		sort(vec[j].begin(), vec[j].end());

	dfs(vec, result1, v);
	bfs(vec, result2, v);

	for (int& node : result1)
		cout << node << " ";

	cout << "\n";

	for (int& node : result2)
		cout << node << " ";
}
