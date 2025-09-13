#include <iostream>
#include <vector>
#include <utility>;
#include <queue>
#include <stack>
using namespace std;

void bfs(vector<pair<char, int>>& path, int a, int b)
{
	queue<int> que;
	que.push(a);
	int curr, tmp;

	while (!que.empty())
	{
		curr = que.front();
		if (curr == b)
			return;
		que.pop();
		
		tmp = curr * 2 % 10000;
		if (path[tmp].second == -1)
		{
			que.push(tmp);
			path[tmp] = { 'D', curr };
		}

		tmp = (curr == 0) ? 9999 : curr - 1;
		if (path[tmp].second == -1)
		{
			que.push(tmp);
			path[tmp] = { 'S', curr };
		}

		tmp = (curr / 100 % 10 * 1000) + (curr / 10 % 10 * 100) + (curr % 10 * 10) + (curr / 1000);
		if (path[tmp].second == -1)
		{
			que.push(tmp);
			path[tmp] = { 'L', curr };
		}

		tmp = (curr % 10 * 1000) + (curr / 1000 * 100) + (curr / 100 % 10 * 10) + (curr / 10 % 10);
		if (path[tmp].second == -1)
		{
			que.push(tmp);
			path[tmp] = { 'R', curr };
		}
	}
}

int main()
{
	int t;
	int a, b;

	cin >> t;

	while (t--)
	{
		cin >> a >> b;
		vector<pair<char, int>> path(10001, { ' ', -1 });
		stack<char> s;

		bfs(path, a, b);

		path[a] = { ' ', -1 };
		int start = b;

		while (path[start].second != -1)
		{
			s.push(path[start].first);
			start = path[start].second;
		}

		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}

		cout << "\n";
	}

	return 0;
}
