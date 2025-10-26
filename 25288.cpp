#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string str1;
	cin >> n;
	cin >> str1;
	string  str2(str1.rbegin(), str1.rend());
	string result;

	for(int i = 1; i <= n; ++i)
	{
		if (i % 2 == 0)
			result += str2;
		else
			result += str1;
	}

	cout << result;
	return 0;
}
