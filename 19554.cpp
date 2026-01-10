#include <iostream>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll min = 1, max = n;

	while (min <= max)
	{
		ll query = min + (max - min) / 2;
		int answer;

		cout << "? " << query << endl;
		cin >> answer;

		if (answer == -1)
			min = query + 1;
		else if (answer == 1)
			max = query - 1;
		else
		{
			cout << "= " << query << endl;
			break;
		}	
	}

	return 0;
}
