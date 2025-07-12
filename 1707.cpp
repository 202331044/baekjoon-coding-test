#include "iostream"
#include "vector"
#include "queue"
#include "utility"

using namespace std;

bool bfs(vector<vector<int>>& vec, vector<pair<bool, bool>>& visited, int v, int e, int node)
{

	queue <int> que;

	que.push(node);
	visited[node].first = true;
	visited[node].second = true;

	while(!que.empty())
	{
		int curr_node = que.front();
		int size = vec[curr_node].size();
		int curr_label = visited[curr_node].second;

		for (int i = 0; i < size; i++)
		{
			int next_node = vec[curr_node][i];

			if (visited[next_node].first == false)
			{
				que.push(next_node);
				visited[next_node].first = true;
				visited[next_node].second = !curr_label;
			}
			else
			{
				if (visited[next_node].second == curr_label)
					return false;
			}
		}
		que.pop();
	}
	return true;
}

int main()
{
	int k, v, e;
	int n1, n2;
	bool check = true;

	cin >> k;

	while (k--)
	{
		cin >> v >> e;
		
		vector<vector<int>> vec(v+1, vector<int>());
		vector<pair<bool, bool>> visited(v + 1);

		for (int i = 0; i < e; i++)
		{
			cin >> n1 >> n2;
			vec[n1].push_back(n2);
			vec[n2].push_back(n1);
		}
		
		for (int i = 1; i <= v; i++)
		{
			if (visited[i].first == false)
			{
				if (bfs(vec, visited, v, e, i) == false)
				{
					cout << "NO" << "\n";
					check = false;
					break;
				}					
			}
		}

		if(check == true)
			cout << "YES" << "\n";

		check = true;
	}
	return 0;
}
