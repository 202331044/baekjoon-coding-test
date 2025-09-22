#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int edge = 0;
long long maxLen = 0;

void dfs(vector <vector<pair<int, int>>>& vec, vector<bool>& visited, int curr_node, long long curr_dist)
{
	for (auto& next: vec[curr_node])
	{
		int next_node = next.first;
		int next_dist = next.second;

		if (visited[next_node] == false)
		{
			visited[next_node] = true;
			curr_dist += next_dist;

			if (curr_dist > maxLen)
			{
				maxLen = curr_dist;
				edge = next_node;
			}	

			dfs(vec, visited, next_node, curr_dist);
			curr_dist -= next_dist;
		}
	}
}

int main()
{
	const int MAX = 100000;
	int n;
	int s, e;
	long long d;
	vector < vector<pair<int, int>>> vec(MAX + 1);
	vector<bool> visited1(MAX + 1);
	vector<bool> visited2(MAX + 1);
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		while (1)
		{
			cin >> e;
			if (e == -1)
				break; 
			cin >> d;
			vec[s].push_back({e, d});
		}
	}

	visited1[1] = true;
	dfs(vec, visited1, 1, 0);

	visited2[edge] = true;
	dfs(vec, visited2, edge, 0);

	cout << maxLen;

	return 0;
}
