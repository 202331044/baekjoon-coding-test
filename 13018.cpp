#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (n - k < 1)
	{
		cout << "Impossible";
		return 0;
	}

	vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i)
		vec[i] = i;

	int result = n - 1, idx = 2;
	while (idx <= n && result > k)
	{
		swap(vec[idx - 1], vec[idx]);
		idx++;
		result--;
	}

	if (result == k)
	{
		for (int i = 1; i <= n; ++i)
			cout << vec[i] << " ";
	}
	else
		cout << "Impossible";

	return 0;
}
