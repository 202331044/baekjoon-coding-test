#include "iostream"
#include "vector"
#include "queue"
#include "utility"

using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& dist)
{
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		auto curr = pq.top();
		int curr_dist = curr.first;
		int curr_node = curr.second;

		pq.pop();

		if (curr_dist > dist[curr_node])
			continue;

		for (auto next : graph[curr_node])
		{
			int next_dist = next.first;
			int next_node = next.second;

			if (dist[next_node] > curr_dist + next_dist)
			{
				dist[next_node] = curr_dist + next_dist;
				pq.push({ dist[next_node], next_node });
			}
		}

		
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	const int INF = 1e9;
	int n, e, s;
	int u, v, w;

	cin >> n >> e;
	cin >> s;

	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> dist(n + 1, INF);

	for (int i = 0; i < e; ++i)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ w, v });
	}

	dijkstra(s, graph, dist);

	int size = dist.size();

	for(int j = 1; j < size; ++j)
	{
		if (dist[j] >= INF)
			cout << "INF" << "\n";
		else
			cout << dist[j] << "\n";
	}

	return 0;
}
