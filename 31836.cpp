#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> a, b;
	cin >> n;

	for (int i = n; i >= 3; i -= 3)
	{
		b.push_back(i);
		a.push_back(i - 1);
		a.push_back(i - 2);
	}

	if (n % 3 == 2)
	{
		a.push_back(1);
		b.push_back(2);
	}

	cout << a.size() << "\n";
	for (auto tmp : a)
		cout << tmp << " ";
	cout << "\n";

	cout << b.size() << "\n";
	for (auto tmp : b)
		cout << tmp << " ";
	cout << "\n";

	return 0;
}
