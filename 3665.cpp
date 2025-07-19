#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

void inorder(vector<int>& order, vector<vector<bool>>& adj, vector<int>& indegree, int n)
{
	queue<int> que;
	queue<int> res;

	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	while (!que.empty())
	{
		if (que.size() != 1)
		{
			cout << "?\n";
			return;
		}
		int curr = que.front();
		res.push(curr);
		que.pop();

		for (int j = 1; j <= n; ++j)
		{
			if (adj[curr][j])
			{
				if (--indegree[j] == 0)
					que.push(j);
			}
		}
	}

	if (res.size() != n)
		cout << "IMPOSSIBLE\n";
	else
	{
		while (!res.empty())
		{
			cout << res.front() << " ";
			res.pop();
		}
		cout << "\n";
	}
}

int main()
{
	int t, n, m;
	int num;
	int m1, m2;

	cin >> t;

	while (t--)
	{
		vector<int> order;
		vector<vector<bool>> adj(501, vector<bool>(501));
		vector<int> indegree(501, 0);
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			order.push_back(num);
		}

		for (int j = 0; j < n-1; ++j) 
		{
			for (int k = j+1; k < n; ++k)
			{
				adj[order[j]][order[k]] = true;
				indegree[order[k]]++;
			}
		}

		cin >> m;

		for (int l = 0; l < m; ++l)
		{
			cin >> m1 >> m2; 
			if (adj[m1][m2] == true)
			{
				adj[m1][m2] = false;
				adj[m2][m1] = true;

				indegree[m1]++;
				indegree[m2]--;
			}
			else
			{
				adj[m1][m2] = true;
				adj[m2][m1] = false;
	
				indegree[m1]--;
				indegree[m2]++;

			}
		}
		inorder(order, adj, indegree, n);
	}

	return 0;
}
