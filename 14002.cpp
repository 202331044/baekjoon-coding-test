#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n;
	int max = 1, pos = 0;
	stack<int> s;

	cin >> n;
	vector<vector<int>> vec(n+1, vector<int>(2, 1));
	vector<int> path(n + 1, -1);

	for (int i = 0; i < n; ++i)
		cin >> vec[i][0];

	for (int j = 0; j < n; ++j)
	{
		for (int k = 0; k < j; ++k)
		{
			if (vec[j][0] > vec[k][0] && vec[j][1] <= vec[k][1])
			{
				vec[j][1] = vec[k][1] + 1;
				path[j] = k;

				if (max < vec[j][1])
				{
					max = vec[j][1];
					pos = j;
				}
			}
		}
	}

	cout << max << "\n";

	while (pos >= 0)
	{
		s.push(vec[pos][0]);
		pos = path[pos];
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
		
	return 0;
}
