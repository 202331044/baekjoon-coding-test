#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(9);

	double x, y, d, t;
	double time = 0;
	cin >> x >> y >> d >> t;

	double dist = sqrt(x * x + y * y);
	time = dist;

	if(d > t)
	{
		int n = dist / d;
		if (n == 0)
		{
			time = min(time, t + (d - dist));
			time = min(time, 2 * t);
		}
		else
		{
			time = n * t + (dist - d * n);
			time = min(time, (n + 1) * t);
		}
	}

	cout << time;
	return 0;
}
