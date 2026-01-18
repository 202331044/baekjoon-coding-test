#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	char ans;
	vector<vector<int>> beat(n);
	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
		vec[i] = i;

	while (vec.size() > 1)
	{
		vector<int> tmp;
		for (int i = 0; i < vec.size() - 1; i += 2)
		{
			int a = vec[i], b = vec[i + 1];

			cout << "? " << a << " " << b << endl;
			cin >> ans;

			if (ans == '<')
			{
				beat[a].push_back(b);
				tmp.push_back(a);
			}
			else
			{
				beat[b].push_back(a);
				tmp.push_back(b);
			}
		}
		if (vec.size() % 2 != 0)
			tmp.push_back(vec[vec.size() - 1]);
		
		vec = tmp;
	}
	
	int minIdx = vec[0];
	vec = beat[minIdx];

	while (vec.size() > 1)
	{
		vector<int> tmp;
		for (int i = 0; i < vec.size() - 1; i += 2)
		{
			int a = vec[i], b = vec[i + 1];
			
			cout << "? " << a << " " << b << endl;
			cin >> ans;

			if (ans == '<')
			{
				beat[a].push_back(b);
				tmp.push_back(a);
			}
			else
			{
				beat[b].push_back(a);
				tmp.push_back(b);
			}
		}
		if (vec.size() % 2 != 0)
			tmp.push_back(vec[vec.size() - 1]);

		vec = tmp;
	}

	cout << "! " << vec[0] << endl;
	return 0;
}
