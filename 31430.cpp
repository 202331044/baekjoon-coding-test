#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	if (t == 1)
	{
		ll a, b, result;
		cin >> a >> b;
		result = a + b;

		string str;
		while (result != 0)
		{
			char c = 'a' + (result % 26);
			str += c;
			result /= 26;
		}

		int size = 13 - str.size();
		for (int i = 0; i < size; ++i)
			str += 'a';

		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	else
	{
		string str;
		cin >> str;

		ll result = 0;
		for(char c: str)
			result = (result * 26) + (c - 'a');

		cout << result << endl;
	}

	return 0;
}
