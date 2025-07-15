#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

queue<int> inDegree(vector<vector<int>>& vec, vector<int>& degree, int n)
{
	queue<int> que;
	vector<bool>visited(n + 1);
	while ((int)que.size() != n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (degree[i] == 0 && visited[i] == false)
			{
				que.push(i);
				visited[i] = true;
				for (int node : vec[i])
				{
					degree[node]--;
				}
			}
		}
	}
	
	return que;
}

int main()
{
	int n, m;
	int s, e;
	cin >> n >> m;

	vector<vector<int>> vec(n+1, vector<int>());
	vector<int>degree(n+1);
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		vec[s].push_back(e);
		degree[e] += 1;
	}

	queue<int> que = inDegree(vec, degree, n);
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	return 0;
}
