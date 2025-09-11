#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void bfs(vector<int>& vec, vector<int>& path, int n, int k)
{
	queue<int> que;
	que.push(n);
	while (!que.empty())
	{
		int curr = que.front();
		if (curr == k) return;
		if (curr + 1 <= 100000 && vec[curr + 1] == -1)
		{
			que.push(curr + 1);
			vec[curr + 1] = vec[curr] + 1;
			path[curr + 1] = curr;
		}
		if (curr - 1 >= 0 && vec[curr - 1] == -1)
		{
			que.push(curr - 1);
			vec[curr - 1] = vec[curr] + 1;
			path[curr - 1] = curr;
		}
		if (curr * 2 <= 100000 && vec[curr * 2] == -1)
		{
			que.push(curr * 2);
			vec[curr * 2] = vec[curr] + 1;
			path[curr * 2] = curr;
		}
		que.pop();
	}
}

int main()
{
	int n, k;
	vector<int> vec(100001, -1);
	vector<int> path(100001, -1);

	cin >> n >> k;

	vec[n] = 0;
	bfs(vec, path, n, k);
	cout << vec[k] << "\n";

	int i = k;
	stack<int> s;

	while (i != -1)
	{
		s.push(i);
		i = path[i];
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
