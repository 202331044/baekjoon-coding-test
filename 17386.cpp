#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	long long x, y;
};

int ccw(Point& a, Point& b, Point& c)
{
	long long x1 = (b.x - a.x);
	long long y1 = (b.y - a.y);
	long long x2 = (c.x - b.x);
	long long y2 = (c.y - b.y);

	long long result = (x1 * y2) - (x2 * y1);

	if (result > 0) return 1;
	else if (result < 0) return-1;
	else return 0;
}

int main()
{
	vector<Point> vec(4);
	long long x, y;
	for (int i = 0; i < 4; ++i)
	{
		cin >> x >> y;
		vec[i] = { x, y };
	}

	int res1 = ccw(vec[0], vec[1], vec[2]);
	res1 *= ccw(vec[0], vec[1], vec[3]);

	int res2 = ccw(vec[2], vec[3], vec[0]);
	res2 *= ccw(vec[2], vec[3], vec[1]);

	if (res1 < 0 && res2 < 0)
		cout << 1;
	else
		cout << 0;

	return 0;
}
