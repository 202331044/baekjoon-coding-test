#include "iostream"
#include "queue"
#include "utility"
using namespace std;

int bfs(int n, int k)
{
	queue<pair<int, int>> que;
	vector<bool> visited(100001);
	que.push({ n, 0 });
	int pos, weight = 0;
	while (!que.empty())
	{
		pos = que.front().first;
		weight = que.front().second;

		if (pos == k)
			break;

		if (pos * 2 <= 100000 && visited[pos * 2] == false)
		{
			que.push({ pos * 2, weight });
			visited[pos * 2] = true;
		}
		if (pos - 1 >= 0 && visited[pos-1] == false)
		{
			que.push({ pos -1, weight + 1});
			visited[pos - 1] = true;
		}
		if (pos + 1 <= 100000 && visited[pos + 1] == false)
		{
			que.push({ pos + 1, weight + 1 });
			visited[pos + 1] = true;
		}

		que.pop();
	}
	return weight;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}
