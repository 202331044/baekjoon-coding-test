#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

vector<bool> visited(100001);
vector<int> result(100001);
int cnt = 1;
queue<int> que;

void bfs(vector<vector<int>>& vec, int & r)
{
	int size = vec.size();
	visited[r] = true;
	result[r] = cnt;
	cnt++;
	que.push(r);
	while (!que.empty())
	{
		int u = que.front();
		for (int& node : vec[u])
		{
			if (!visited[node])
			{
				visited[node] = true;
				result[node] = cnt;
				cnt++;
				que.push(node);
			}
		}
		que.pop();
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

	for (int j = 0; j < size; j++)
		sort(vec[j].begin(), vec[j].end());

	bfs(vec, r);

	for (int k = 1; k <= n; k++)
		cout << result[k] << "\n";

	return 0;
}
