#include "iostream"
#include "queue"
#include "vector"
#include "utility"

using namespace std;

const int MAX = 1e7;

vector<int> dijkstra(vector<vector<pair<int, int>>>& vec, int start, int n)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> distance(n+1, MAX);
	
	pq.push({ 0, start });
	distance[start] = 0;

	while (!pq.empty())
	{

		auto curr = pq.top();
		int weight = curr.first;
		int node = curr.second;
		pq.pop();

		if (distance[node] < weight)
			continue;

		for (auto& next : vec[node])
		{
			int nextWeight = next.first;
			int nextNode = next.second;
	
			if (distance[nextNode] > weight + nextWeight)
			{
				distance[nextNode] = weight + nextWeight;
				pq.push({distance[nextNode], nextNode });
			}
		}
	}
	return distance;
}

int main()
{

	int n, e;
	int a, b, c;
	int v1, v2;

	cin >> n >> e;
	
	vector<vector<pair<int, int>>> vec(n+1);

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		vec[a].push_back({ c, b });
		vec[b].push_back({ c, a });
	}
	
	cin >> v1 >> v2;

	vector<int> dist1 = dijkstra(vec, 1, n);
	vector<int> distv1 = dijkstra(vec, v1, n);
	vector<int> distv2 = dijkstra(vec, v2, n);
	
	int path1 = dist1[v1] + distv1[v2] + distv2[n];
	int path2 = dist1[v2] + distv2[v1] + distv1[n];

	int res = min(path1, path2);

	if (res >= MAX)
		cout << -1;
	else
		cout << res;
	return 0;
}
