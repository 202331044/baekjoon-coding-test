#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;
	vector<int> vec(n + 1);
	int s = 1;
	int max = n, min = 1;

	while (s <= n)
	{
		if (s == n)
		{
			vec[s] = max;
			break;
		}	
		vec[s++] = max--;
		vec[s++] = min++;
	}

	for (int j = 1; j <= n; ++j)
		cout << vec[j] << " ";
	return 0;
}
