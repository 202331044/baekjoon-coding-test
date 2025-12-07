#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
};

int ccw(Point&a, Point&b, Point&c)
{
	double x1 = (b.x - a.x), y1 = (b.y - a.y);
	double x2 = (c.x - a.x),  y2 = (c.y - a.y);
	double result = x1 * y2 - x2 * y1;

	if (result < 0) return -1;
	else if (result > 0) return 1;
	else return 0;
}

int main()
{
	const double MAX = 1000000001;
	int n;
	cin >> n;

	vector<Point> vec(n);
	vector<Point> pos(3);
	for (int i = 0; i < n; ++i)
		cin >> vec[i].x >> vec[i].y;

	for (int j = 0; j < 3; ++j)
		cin >> pos[j].x >> pos[j].y;

	for (int idx = 0; idx < 3; ++idx)
	{
		auto curr = pos[idx];
		double x = MAX, y = curr.y + 1;
		Point tmp = { x, y };
		int cnt = 0;
		for (int k = 0; k < n; ++k)
		{
			auto p1 = vec[k];
			auto p2 = vec[(k + 1) % n];
			if (min(p1.y, p2.y) <= curr.y && max(p1.y, p2.y) >= curr.y)
			{
				int res1 = ccw(p1, p2, curr);
				int res2 = ccw(p1, p2, tmp);
				int res3 = ccw(curr, tmp, p1);
				int res4 = ccw(curr, tmp, p2);
				
				if (res1 == 0 && 
					min(p1.x, p2.x) <= curr.x &&
					max(p1.x, p2.x) >= curr.x)
				{
					cnt = 1;
					break;
				}
				else if (res1 * res2 <= 0 && res3 * res4 <= 0)
					cnt++;
			}
		}
		if (cnt == 0 || cnt % 2 == 0)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
	return 0;
}
