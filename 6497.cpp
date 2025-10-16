#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 200001;

int prim(vector<vector<pair<int, int>>>& vec)
{
	int total = 0;
	vector<bool> visited(MAX, false);
	priority_queue < pair<int, int>, vector<pair<int ,int>>, greater<>> pq;
	pq.push({ 0, 0 });
	
	while (!pq.empty())
	{
		auto curr = pq.top();
		int dist = curr.first;
		int city = curr.second;
		pq.pop();
		
		if (visited[city])
			continue;
		total += dist;
		visited[city] = true;

		for (auto next : vec[city])
		{
			int nextCity = next.first;
			int nextDist = next.second;
			if (visited[nextCity] == false)
				pq.push({ nextDist, nextCity });
		}
	}
	return total;
}

int main()
{
	int n, m;
	int x, y, z;

	while (1)
	{
		int total = 0;
		vector<vector<pair<int, int>>> vec(MAX);
		cin >> m >> n;
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y >> z;
			vec[x].push_back({ y, z });
			vec[y].push_back({ x, z });
			total += z;
		}

		cout << total - prim(vec) << "\n";
	}
	return 0;
}
