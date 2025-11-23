#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

int answer = 0;
struct Point
{
	double x, y;
};

int ccw(Point& a, Point& b, Point& c)
{
	double x1 = (a.x - b.x), y1 = (a.y - b.y);
	double x2 = (c.x - b.x), y2 = (c.y - b.y);
	double res = x1 * y2 - x2 * y1;

	if (res < 0) return -1;
	else if (res > 0) return 1;
	else return 0;
}

void dfs(vector<double>& vec, vector<bool>& visited, vector<double>& arr)
{
	if (arr.size() == 8)
	{
		vector<Point> coord;
		for (int i = 0; i < 8; ++i)
		{
			coord.push_back({ arr[i] * cos((45 * (i + 1 )) * (M_PI / 180)),
				arr[i] * sin((45 * (i + 1)) * (M_PI / 180)) });
		}
		
		for (int j = 0; j < 8; ++j)
			if (ccw(coord[j], coord[(j + 1) % 8], coord[(j + 2) % 8]) == 1) return;
		answer++;
	}

	for (int k = 0; k < 8; ++k)
	{
		if (visited[k]) continue;
		visited[k] = true;
		
		arr.push_back(vec[k]);
		dfs(vec, visited, arr);
		
		visited[k] = false;
		arr.pop_back();
	}
}

int main()
{
	vector<double> vec(8);
	vector<bool> visited(8);
	vector<double> arr;

	for (int i = 0; i < 8; ++i)
		cin >> vec[i];

	dfs(vec, visited, arr);
	cout << answer;

	return 0;
}
