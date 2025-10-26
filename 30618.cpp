#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n + 1);
	int s = 1, e = n;
	int num = 1;

	while (s <= e)
	{
		if (s == e)
		{
			vec[s] = num;
			break;
		}
		vec[s++] = num++;
		vec[e--] = num++;
	}

	for (int i = 1; i <= n; ++i)
		cout << vec[i] << " ";
	return 0;
}
