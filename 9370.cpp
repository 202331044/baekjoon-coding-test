#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int SIZE = 1e7;

vector<int> dijkstra(vector<vector<pair<int, int>>>& vec, int s, int n)
{
	vector<int> distance(n + 1, SIZE);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push({ 0, s });
	distance[s] = 0;

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();
		int currDist = curr.first;
		int currNode = curr.second;

		if (distance[currNode] < currDist)
			continue;

		for (auto next : vec[currNode])
		{
			int nextDist = next.first;
			int nextNode = next.second;
			
			if (distance[nextNode] > nextDist + currDist)
			{
				distance[nextNode] = nextDist + currDist;
				pq.push({ distance[nextNode], nextNode });
			}
		}
	}
	return distance;
}

int main()
{
	int count;
	int n, m, t;
	int s, g, h;
	int a, b, d;
	int tmp;

	cin >> count;

	while (count--)
	{
		vector <vector<pair<int, int>>> vec(2001);
		priority_queue<int, vector<int>, greater<>> dst;

		cin >> n >> m >> t;
		cin >> s >> g >> h;
		
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> d;
			vec[a].push_back({ d, b });
			vec[b].push_back({ d, a });
		}

		for (int j = 0; j < t; ++j)
		{
			cin >> tmp;
			dst.push(tmp);
		}

		vector<int> distance = dijkstra(vec, s, n);
		vector<int> distance_g = dijkstra(vec, g, n);
		vector<int> distance_h = dijkstra(vec, h, n);

		int path1, path2, minpath;

		while (!dst.empty())
		{
			int it = dst.top();

			path1 = distance[g] + distance_g[h] + distance_h[it];
			path2 = distance[h] + distance_h[g] + distance_g[it];

			minpath = path1 > path2 ? path2 : path1;

			if (minpath < SIZE && distance[it] == minpath)
				cout << it << " ";
			dst.pop();
		}
		cout << "\n";
	}
	return 0;
}
