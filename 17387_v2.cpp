#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int ccw(pll& a, pll& b, pll& c)
{
	ll x1 = (b.first - a.first), y1 = (b.second - a.second);
	ll x2 = (c.first - a.first), y2 = (c.second - a.second);
	ll result = x1 * y2 - x2 * y1;

	if (result < 0) return -1;
	else if (result > 0) return 1;
	else return 0;
}

int main()
{
	pll a, b, c, d;
	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;

	int res1 = ccw(a, b, c) * ccw(a, b, d);
	int res2 = ccw(c, d, a) * ccw(c, d, b);

	if (res1 == 0 && res2 == 0)
	{
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		if (a <= d && c <= b)
			cout << 1;
		else
			cout << 0;
	}
	else if (res1 <= 0 && res2 <= 0)
		cout << 1;
	else
		cout << 0;

	return 0;
}
