#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

int ccw(pll& a, pll& b, pll& c)
{
	ll res = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	
	if (res < 0) return -1;
	else if (res > 0) return 1;
	else return 0;
}

pdd findIntersection(pll& a, pll& b, pll&c, pll&d)
{
	double A1 = (b.second - a.second), B1 = (a.first - b.first);
	double C1 = A1 * a.first + B1 * a.second;
	double A2 = (d.second - c.second), B2 = (c.first - d.first);
	double C2 = A2 * c.first + B2 * c.second;

	pdd res;
	res.first = (C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);
	res.second = (A2 * C1 - A1 * C2) / (A2 * B1 - A1 * B2);
	
	cout << fixed << setprecision(9);
	return res;
}

int main()
{
	pll p1, p2, p3, p4;
	cin >> p1.first >> p1.second >> p2.first >> p2.second;
	cin >> p3.first >> p3.second >> p4.first >> p4.second;

	int c1 = ccw(p1, p2, p3), c2 = ccw(p1, p2, p4);
	int c3 = ccw(p3, p4, p1), c4 = ccw(p3, p4, p2);

	if (c1 * c2 == 0 && c3 * c4 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		if (max(p1, p3) <= min(p2, p4))
		{
			cout << 1 << "\n";
			if (c1 != c2 && c3 != c4)
			{
				pdd res = findIntersection(p1, p2, p3, p4);
				cout << res.first << " " << res.second;
			}
			else if (p1 == p4)
				cout << p1.first << " " << p1.second;
			else if (p2 == p3)
				cout << p2.first << " " << p2.second;
		}
		else
			cout << 0;
	}
	else if (c1 * c2 <= 0 && c3 * c4 <= 0)
	{
		pdd res = findIntersection(p1, p2, p3, p4);
		cout << 1 << "\n";
		cout << res.first << " " << res.second;
	}
	else
		cout << 0;

	return 0;
}
