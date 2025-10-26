#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string str;
	cin >> n;

	for (int i = 0; i < n; ++i)
		str += 'a';

	cout << str;
	return 0;
}
