#include "iostream"
#include "queue"
#include "vector"
#include "utility"

using namespace std;

void bfs(int n, int k, vector<pair<bool, int>>& visited)
{
	queue<int> que;
	int curr;

	que.push(n);
	visited[n] = { true, 0 };

	while (!que.empty())
	{
		curr = que.front();

		if (curr == k)
			break;
		
		if (curr - 1 >= 0 && visited[curr - 1].first == false)
		{
			que.push(curr - 1);
			visited[curr - 1] = { true, visited[curr].second + 1 };
		}
		if (curr + 1 <= 100000 && visited[curr +1].first == false)
		{
			que.push(curr + 1);
			visited[curr + 1] = { true, visited[curr].second + 1 };
		}
		if (curr * 2 <= 100000 && visited[curr * 2].first == false)
		{
			que.push(curr * 2);
			visited[curr * 2] = { true, visited[curr].second + 1 };
		}

		que.pop();
	}
}

int main()
{
	int n, k;
	vector<pair<bool, int>> visited(100001);

	cin >> n >> k;

	bfs(n, k, visited);

	cout << visited[k].second;

	return 0;
}
