#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, q, answer;
	cin >> m >> n >> q;

	vector<int> vec(n);
	vector<int> res(n, 1);
	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	for (int i = 1; i <= m; ++i)
	{
		cout << "? " << i << " " << i << endl;
		cin >> answer;

		if (answer < vec[i - 1])
			res[i - 1] = answer + 1;
		else
			res[i - 1] = 1;
	}

	cout << "! ";
	for (int j = 0; j < n; ++j)
		cout << res[j] << " ";
	cout << endl;

	return 0;
}
