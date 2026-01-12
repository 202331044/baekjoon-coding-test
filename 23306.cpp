#include <iostream>
using namespace std;

int main()
{
	int n, ans1, ans2;
	int result = 0;
	cin >> n;

	cout << "? " << 1 << endl;
	cin >> ans1;
	cout << "? " << n << endl;
	cin >> ans2;

	if (ans1 == ans2)
		result = 0;
	else if (ans1 == 1 && ans2 == 0)
		result = -1;
	else if (ans1 == 0 && ans2 == 1)
		result = 1;
	cout << "! " << result << endl;

	return 0;
}
