#include "iostream"
#include "vector"
#include "queue"

using namespace std;

void topologicalSort(int n, vector<vector<int>>& vec, vector<int>& indegree)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 1; i <= n; ++i)
	{
		if(indegree[i]== 0)
			pq.push(i);
	}
	
	while (!pq.empty())
	{
		int curr = pq.top();
		--indegree[curr];
		pq.pop();

		cout << curr << " ";

		for(int node: vec[curr])
		{
			if (--indegree[node] == 0)
				pq.push(node);
		}
	}
}

int main()
{
	int n, m;
	int s, e;

	cin >> n >> m;

	vector<int> indegree(n + 1);
	vector<vector<int>> vec(n + 1);

	for (int k = 0; k < m; ++k)
	{
		cin >> s >> e;
		vec[s].push_back(e);
		indegree[e]++;
	}

	topologicalSort(n, vec, indegree);

	return 0;
}
