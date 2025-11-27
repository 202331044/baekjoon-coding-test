#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
	long long x, y;
};

int ccw(Point& a, Point& b, Point& c)
{
	long long x1 = (a.x - b.x);
	long long y1 = (a.y - b.y);
	long long x2 = (c.x - a.x);
	long long y2 = (c.y - a.y);

	long long result = x1 * y2 - x2 * y1;

	if (result < 0) return -1;
	else if (result > 0) return 1;
	return 0;
}

int main()
{
	Point a1, a2, b1, b2;
	cin >> a1.x >> a1.y >> a2.x >> a2.y;
	cin >> b1.x >> b1.y >> b2.x >> b2.y;

	int res1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
	int res2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);

	if (res1 == 0 && res2 == 0)
	{
		if (min(a1.x, a2.x) <= max(b1.x, b2.x) &&
			min(b1.x, b2.x) <= max(a1.x, a2.x) &&
			min(a1.y, a2.y) <= max(b1.y, b2.y) &&
			min(b1.y, b2.y) <= max(a1.y, a2.y))
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
