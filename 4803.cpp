#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
	int n, m;
	int n1, n2;
	int cnt = 1;

	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		vector<int> vec(n + 1, -1);
		unordered_set<int> cycle;
		unordered_set<int> result;

		int g1, g2, tmp, group = 1;

		for (int i = 0; i < m; ++i)
		{
			cin >> n1 >> n2;

			if (vec[n1] == -1 && vec[n2] == -1)
			{
				vec[n1] = vec[n2] = group;
				group++;
			}
			else if(vec[n1] == -1 || vec[n2] == -1)
			{
				tmp = vec[n1] != -1 ? vec[n1] : vec[n2];
				vec[n1] = vec[n2] = tmp;
			}
			else if (vec[n1] != vec[n2])
			{
				if (vec[n1] < vec[n2])
				{
					g1 = vec[n1];
					g2 = vec[n2];
				}
				else
				{
					g1 = vec[n2];
					g2 = vec[n1];
				}

				for (int j = 1; j < n + 1; ++j)
				{
					if (vec[j] == g2)
						vec[j] = g1;
				}
			}
			else
			{
				cycle.insert(vec[n1]);
			}
		}
		
		for (auto it = cycle.begin(); it != cycle.end(); ++it)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				if (vec[j] == *it)
					vec[j] = -2;	
			}
		}

		for (int k = 1; k < n + 1; ++k)
		{
			if (vec[k] == -1)
				result.insert(group++);
			else if (vec[k] != -2)
				result.insert(vec[k]);
		}

		int edges = result.size();

		if (edges == 0)
			cout << "Case " << cnt << ": No trees." << "\n";
		else if (edges == 1)
			cout << "Case " << cnt << ": There is one tree." << "\n";
		else
			cout << "Case " << cnt << ": A forest of " << edges << " trees." << "\n";

		cnt++;
	}

	return 0;
}
