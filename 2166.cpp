#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	long long x, y;
};

int main()
{
	int n, x, y;
	long long sum = 0;
	double area = 0;
	cin >> n;
	vector<Point> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		vec[i] = { x, y };
	}
	
	for (int j = 0; j < n; ++j)
	{
		int k = (j + 1) % n;
		sum += (vec[j].x * vec[k].y) - (vec[j].y * vec[k].x);
	}

	area = llabs(sum)/(double)2;

	cout << fixed;
	cout.precision(1);
	cout << area;
	cout.unsetf(ios::fixed);

	return 0;
}
