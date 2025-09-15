#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <stack>

using namespace std;

int s, e;

void dijkstra(vector<vector<pair<int, int>>>& vec, vector<int>& dist, vector<int>& path)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, s});
	dist[s] = 0;

	while (!pq.empty())
	{
		auto curr = pq.top();
		int weight = curr.first;
		int pos = curr.second;
		pq.pop();

		if (weight > dist[pos]) continue;

		for (auto& next : vec[pos])
		{
			int next_pos = next.first;
			int next_weight = next.second;

			if (dist[pos] + next_weight < dist[next_pos])
			{			
				dist[next_pos] = dist[pos] + next_weight;
				pq.push({ dist[next_pos], next_pos });
				path[next_pos] = pos;
			}
		}
	}
}

int main()
{
	int n, m;
	int a, b, c;
	const int INF = 1e9;

	vector<vector<pair<int, int>>> vec(1001);
	vector<int> dist(1001, INF);
	vector<int> path(1001, -1);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		vec[a].push_back({b, c});
	}

	cin >> s >> e;

	dijkstra(vec, dist,path);
	cout << dist[e] << "\n";

	stack<int> stk;
	int p = e;

	while(path[p] != -1)
	{
		stk.push(p);
		p = path[p];
	}	

	stk.push(s);
	cout << stk.size() << "\n";

	while (!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}
