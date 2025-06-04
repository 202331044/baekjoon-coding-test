#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

vector<bool> visited(100001);
queue<int> que;
vector<int> result(100001);
int cnt = 1;

void bfs(vector<vector<int>>& vec, int &r)
{
	int tmp;
	visited[r] = true;
	que.push(r);
	result[r] = cnt++;

	while (!que.empty())
	{
		tmp = que.front();

		for (int& node : vec[tmp])
		{
			if (!visited[node])
			{
				que.push(node);
				result[node] = cnt++;
				visited[node] = true;
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

	for (int j = 1; j <= n; j++)
		sort(vec[j].begin(), vec[j].end(), greater<>());
	
	bfs(vec, r);

	for(int k = 1; k <= n; k++)
		cout << result[k] << "\n";

	return 0;
}
