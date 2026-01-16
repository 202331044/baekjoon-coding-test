#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, k;
		cin >> n >> k;
		vector<int> vec(k, 0);
		for (int i = 0; i < k; ++i)
		{
			cin >> vec[i];
		}

		auto it = find(vec.begin(), vec.end(), 1);
		if (it == vec.end())
		{
			cout << n << " " << k + 1 << endl;
			cout << 1 << " ";
			for (int j = 0; j < k; ++j)
				cout << vec[j] << " ";
			cout << endl;
		}
		else
		{
			cout << n << " " << k - 1 << endl;
			for (int j = 0; j < k; ++j)
			{
				if (vec[j] == 1)
					continue;
				cout << vec[j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
