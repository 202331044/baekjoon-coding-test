#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x, y;
};

int main()
{
	int x, y;
	Point u, v;
	vector<Point> vec(3);
	for (int i = 0; i < 3; ++i)
	{
		cin >> x >> y;
		vec[i] = { x, y };
	}

	u = { vec[1].x - vec[0].x, vec[1].y - vec[0].y };
	v = { vec[2].x - vec[1].x, vec[2].y - vec[1].y };

	int result = (u.x * v.y) - (u.y * v.x);
	
	if (result < 0)
		cout << -1;
	else if (result > 0)
		cout << 1;
	else
		cout << 0;
	
	return 0;
}
