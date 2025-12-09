#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double answer = 0;
	cout << fixed;
	cout.precision(3);

	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

	if (r1 + r2 <= d)
		answer = 0;
	else if (d + min(r1, r2) <= max(r1, r2))
		answer = min((M_PI * r1 * r1), (M_PI * r2 * r2));
	else
	{
		double cos1= (r1 * r1 + d * d - r2 * r2) / (2 * r1 * d);
		double cos2 = (r2 * r2 + d * d - r1 * r1) / (2 * r2 * d);
		double theta1 = 2 * acos(cos1);
		double theta2 = 2 * acos(cos2);

		double s1 = r1 * r1 * theta1 * 0.5;
		double s2 = r2 * r2 * theta2 * 0.5;

		s1 -= r1 * r1 * sin(theta1) * 0.5;
		s2 -= r2 * r2 * sin(theta2) * 0.5;
		
		answer = s1 + s2;
	}

	cout << answer;
	return 0;
}
