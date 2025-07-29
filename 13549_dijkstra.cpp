#include "iostream"
#include "vector"
#include "queue"
#include "utility"
using namespace std;

int dijkstra(int n, int k)
{
	const int SIZE = 1e9;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> distance(100001, SIZE);

	pq.push({ 0, n });
	distance[n] = 0;

	while (!pq.empty())
	{
		int weight= pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (pos == k)
			break;
		
		if (distance[pos] < weight)
			continue;

		if (pos + 1 <= 100000 && distance[pos + 1] > weight + 1)
		{
			pq.push({ weight + 1, pos + 1 });
			distance[pos + 1] = weight + 1;
		}
		if (pos - 1 >= 0 && distance[pos - 1] > weight + 1)
		{
			pq.push({ weight + 1, pos - 1 });
			distance[pos - 1] = weight + 1;
		}
		if (pos * 2 <= 100000 && distance[pos * 2] > weight)
		{
			pq.push({ weight, pos * 2 });
			distance[pos * 2] = weight;
		}
	}

	return distance[k];
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << dijkstra(n, k);
	return 0;
}
