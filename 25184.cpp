#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;
	vector<int> vec(n + 1);
	int idx = 1;
	int pre = n - (n/2), post = n;

	while (idx <= n)
	{
		if (idx == n)
		{
			vec[idx] = pre;
			break;
		}
		vec[idx++] = pre--;
		vec[idx++] = post--;
	}

	for (int j = 1; j <= n; ++j)
		cout << vec[j] << " ";
	return 0;
}
